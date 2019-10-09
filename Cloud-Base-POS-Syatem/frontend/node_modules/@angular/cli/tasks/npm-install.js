"use strict";
/**
 * @license
 * Copyright Google Inc. All Rights Reserved.
 *
 * Use of this source code is governed by an MIT-style license that can be
 * found in the LICENSE file at https://angular.io/license
 */
Object.defineProperty(exports, "__esModule", { value: true });
const child_process_1 = require("child_process");
const color_1 = require("../utilities/color");
async function default_1(packageName, logger, packageManager, projectRoot, save = true) {
    const installArgs = [];
    switch (packageManager) {
        case 'cnpm':
        case 'pnpm':
        case 'npm':
            installArgs.push('install');
            break;
        case 'yarn':
            installArgs.push('add');
            break;
        default:
            packageManager = 'npm';
            installArgs.push('install');
            break;
    }
    logger.info(color_1.colors.green(`Installing packages for tooling via ${packageManager}.`));
    if (packageName) {
        installArgs.push(packageName);
    }
    if (!save) {
        installArgs.push('--no-save');
    }
    installArgs.push('--quiet');
    await new Promise((resolve, reject) => {
        child_process_1.spawn(packageManager, installArgs, { stdio: 'inherit', shell: true }).on('close', (code) => {
            if (code === 0) {
                logger.info(color_1.colors.green(`Installed packages for tooling via ${packageManager}.`));
                resolve();
            }
            else {
                reject('Package install failed, see above.');
            }
        });
    });
}
exports.default = default_1;
