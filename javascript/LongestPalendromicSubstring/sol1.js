/**
 * @param {string} s
 * @return {string}
 */
// MANACHER'S ALGORITHM
var convertToNewString = function(str) {
    let newStr = '@#'
    newStr = newStr+str.split('').reduce((prev,next) => {
        return prev+"#"+next
    })
    return newStr+"#$"
}
var longestPalindrome = function(s) {
    if (!s) {
        return ''
    }
    let P = new Array(2*s.length+10)
    P.fill(0)
    let Q = convertToNewString(s);
    let c = 0, r = 0;                // current center, right limit

    for (let i = 1; i < Q.length - 1; i++) {
        // find the corresponding letter in the palidrome subString
        let iMirror = c - (i - c);

        if(r > i) {
            P[i] = Math.min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] === Q[i - 1 - P[i]] && Q[i + 1 + P[i]] && Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length in p.

    let maxPalindrome = 0;
    let centerIndex = 0;

    for (let i = 1; i < Q.length- 1; i++) {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
  
};
