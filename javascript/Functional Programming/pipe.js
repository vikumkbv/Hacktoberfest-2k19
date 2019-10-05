/**
 *
 * @param str {string}
 * @returns {string}
 * @description accept string and output the first letter to uppercase, rest remain unchanged
 * @example
 *   1. capitalize('hello world')        // 'Hello world'
 *   2. capitalize('hacktoberfest-2k19') // 'Hacktoberfest-2k19'
 */
const capitalize = (str) => `${str[0].toUpperCase()}${str.slice(1, str.length)}`

/**
 *
 * @param str {string}
 * @returns {string}
 * @description accept string and return the first letter of string.
 */
const firstChar = (str) => str[0] || ''

/**
 *
 * @param fns
 * @returns {function(*=): *}
 * @description accept list of functions and return a new function which accept initial input
 * @example
 *      const getFirstCharAndCapitalizeIt = pipe(
 *          firstChar,
 *          capitalize
 *      )
 *
 *      console.log(getFirstCharAndCapitalizeIt('hacktoberfest-2k19') // 'H'
 */
const pipe = (...fns) => (initialInput) => fns.reduce((acc, fn) => fn(acc), initialInput)
