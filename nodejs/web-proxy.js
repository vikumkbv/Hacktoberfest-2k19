/* eslint-disable consistent-return */
/* eslint-disable import/order */
/* eslint-disable no-console */
/* eslint-disable no-inner-declarations */

// const fs = require('fs');
const http = require('http');
// const https = require('https');
const express = require('express');
const logger = require('./logger');

const argv = require('./argv');
const port = require('./port');
const setup = require('./middlewares/frontendMiddleware');
const isDev = process.env.NODE_ENV !== 'production';
const ngrok =
  (isDev && process.env.ENABLE_TUNNEL) || argv.tunnel
    ? require('ngrok')
    : false;
const { resolve } = require('path');
const app = express();
const { contextRoot } = require('../internals/buildConfig');

// Setting up Proxy (DO BEFORE FRONTEND MIDDLEWARE!!)
if (isDev) {
  const packageJson = require('../package.json'); // eslint-disable-line
  if (packageJson.proxy) {

    /** @see https://github.com/webpack/webpack-dev-middleware/issues/67#issuecomment-187358393 */
    const httpProxy = require('http-proxy'); // eslint-disable-line
    const apiProxy = httpProxy.createProxyServer({
      rejectUnauthorized: false,
    });

    function stripTailedSlash(text) {
      return text.substr(0, text.lastIndexOf('/'));
    }

    // Bypass Self-signed Certificate
    process.env.NODE_TLS_REJECT_UNAUTHORIZED = '0';

    console.log('Proxy by URLs :');
    Object.keys(packageJson.proxy).forEach(path => {
      const proxy = packageJson.proxy[path];
      const absolutePath = proxy.absoluteUrl === true;
      const useURL = `${absolutePath ? '' : stripTailedSlash(contextRoot)}${path}/`;
      console.log(' - Listen URL :', useURL);
      app.use(useURL, (req, res) => {

        // req.url = req.baseUrl;
        // console.log('proxy to :', req.originalUrl);

        // FIXED Query string not passed into proxy
        // https://stackoverflow.com/a/43904015
        req.url = req.originalUrl;
        apiProxy.web(req, res, {
          target: proxy.target,
          proxyTimeout: 60 * 1000,
          secure: proxy.secure,
        });
        apiProxy.on('error', (err, reqErr, resErr) => {
          console.warn('Proxy error :', err.code);
          try {
            resErr.writeHead(503, {
              'Content-Type': 'text/plain',
            });
            resErr.end(`Error : ${err.code}`);
          } catch (proxyErr) {
            // console.error('Proxy error :', proxyErr);
          }
        });
      });

      console.log(`   Redirect to : ${proxy.target}${path} `);
    });

  }
}

// If you need a backend, e.g. an API, add your custom backend-specific middleware here
// app.use('/api', myApi);

// get the intended host and port number, use localhost and port 3000 if not provided
const customHost = argv.host || process.env.HOST;
const host = customHost || null; // Let http.Server use its default IPv6/4 host
const prettyHost = customHost || 'localhost';

// use the gzipped bundle
/* app.get('*.js', (req, res, next) => {
  req.url = req.url + '.gz'; // eslint-disable-line
  console.log('req.url', req.url);
  res.set('Content-Encoding', 'gzip');
  next();
});
 */
// Start your app.
// Define Create server Initializer

/* eslint-disable no-shadow */
const httpServerInitializer = ({ port, isSSL = false }) => async err => {
  if (err) {
    return logger.error(err.message);
  }

  // Connect to ngrok in dev mode
  if (ngrok) {
    let url;
    try {
      url = await ngrok.connect(port);
    } catch (e) {
      return logger.error(e);
    }
    logger.appStarted(port, prettyHost, url, isSSL);
  } else {
    logger.appStarted(port, prettyHost, undefined, isSSL);
  }

  // In production we need to pass these values in instead of relying on webpack
  setup(app, {
    outputPath: resolve(process.cwd(), 'build'),
    publicPath: '/public/',
  });
};

http.createServer(app).listen(port, host, httpServerInitializer({ port }));
/* https.createServer({
  key: fs.readFileSync('./server/server.key'),
  cert: fs.readFileSync('./server/server.crt'),
}, app).listen(port + 1, host, httpServerInitializer({
  port: port + 1,
  isSSL: true,
})); */

// app.listen(port, host);
