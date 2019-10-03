var lengthOfLongestSubstring = function(s) {
   
    var sLen = s.length,
      maxLen = 0,
      maxStr = '',
      tmpStr,
      posIndex,
      i;
  
    for( i = 0 ; i < sLen; i++ ){
  
      tmpStr = s[i];
      posIndex = maxStr.indexOf(tmpStr);
  
      if(posIndex > -1){
        maxStr = maxStr.substring(posIndex + 1);
      }
  
      maxStr += tmpStr;
      maxLen = Math.max(maxLen, maxStr.length);
    }
  
    return maxLen;
  };