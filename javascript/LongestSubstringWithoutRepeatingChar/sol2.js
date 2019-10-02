/**
 * @param {string} s
 * @return {number}
 */

var checkUnique = function(str) {
    let cache = {}
    for (let ch of str) {
        if (cache[ch]) {
            return false
        } else {
            cache[ch] = 1
        }
    }
       return true
   }
   var lengthOfLongestSubstring = function(s) {
      
       if (s.length === 1) {
           return 1
       }
       
       let left = 0, right = 0, max = 0
       let window = ''
       while (right < s.length) {
           window = s.substring(left, right+1)
           if(checkUnique(window)) {
                if (window.length > max ) {
                   max = window.length
               }
               right++
           } else {
               right = left + max
               left++
               
           }
       }
       return max
   };