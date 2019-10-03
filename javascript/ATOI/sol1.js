/**
 * @param {string} str
 * @return {number}
 */
const INT_MIN = -2147483648
const INT_MAX = 2147483647
var myAtoi = function(str) {
    str = str.trim()
    let neg = str[0]=== '-' ? -1 : 1
    if (str[0] === '-' || str[0] === '+') {
        str = str.substr(1)
    }
    let arr = ['0','1','2','3','4','5','6','7','8','9']
    let abs = 1
    let s = ''
    for (let ch of str) {
        if (arr.indexOf(ch) === -1) {
            break 
        }
        s+=ch
    }
    
    if (s) {
        let val =  neg*parseInt(s)
        if (val < INT_MIN) {
            return INT_MIN
        } else if (val > INT_MAX) {
            return INT_MAX
        } else {
            return val
        }
    } else {
        return 0
    }
};