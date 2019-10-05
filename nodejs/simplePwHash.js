const crypto = require('crypto')

function hash (pass, salt) {
  return crypto.pbkdf2Sync(pass, salt, 100000, 32, 'sha256').toString('hex')
}

let salt = crypto.randomBytes(16).toString('hex')
console.log(hash("p4ssw0rd321", salt))
