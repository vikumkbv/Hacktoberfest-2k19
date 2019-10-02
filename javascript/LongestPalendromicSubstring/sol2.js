/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(str) {
    let maxLength = 1
    let start = 0
    let len = str.length
    let high, low
    for (let i = 0 ; i < len ; i++) {
        low = i-1
        high = i
        while (low >= 0 && high < len && str[low] === str[high]) {
            if (high -low +1 > maxLength) {
                start = low
                maxLength = high -low + 1
            }
            --low
            ++high
        }
        
        	low = i - 1; 
			high = i + 1; 
			while (low >= 0 && high < len 
					&& str[low] === str[high] ){ 
				if (high - low + 1 > maxLength) { 
					start = low; 
					maxLength = high - low + 1; 
				} 
				--low; 
				++high; 
			} 
    }
    return str.substring(start, start + maxLength)
};