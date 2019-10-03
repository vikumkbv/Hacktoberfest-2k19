/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */

var convert = function(s, numRows) {
    if (numRows ===0 || numRows === 1) {
        return s
    }
    let obj = {}
    let count = 0
    for (let i = 0; i< s.length;) {
        let up = numRows
        let down = numRows -2
        let arr = []
        if (count%2 ===0) {
             while (up) {
                 arr.push(s[i])
                 i++
                 up--
             }
        } else {
            arr.push('#')
            while (down) {
                 arr.push(s[i])
                 i++
                 down--
             }
            arr.push('#')
            arr.reverse()
        }
        obj[count++] = arr
    }
    let arr = Object.values(obj)
    s = ''
    for (let i = 0; i<numRows; i++) {
        for (let j = 0; j< arr.length; j++) {
            if (arr[j][i] && arr[j][i] !== '#') {
                s+=arr[j][i]
            }
        }
    }
    return s
};