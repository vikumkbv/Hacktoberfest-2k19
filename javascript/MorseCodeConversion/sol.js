function decodeMorse(morseCode) {
    let morseAlphabet = { 
      '.-': 'A', '-...': 'B', '-.-.': 'C', '-..': 'D', '.': 'E', '..-.': 'F', '--.': 'G', '....': 'H', '..': 'I', '.---': 'J', '-.-': 'K', '.-..': 'L', '--': 'M', '-.': 'N','---': 'O', '.--.': 'P', '--.-': 'Q', '.-.': 'R', '...': 'S', '-': 'T', '..-': 'U','...-': 'V', '.--': 'W', '-..-': 'X', '-.--': 'Y', '--..': 'Z', '···−−−···': 'SOS', '-.--.-': '(', '-.---.': ')'
    }
    morseCode = morseCode.split('   ');
    let i = 0;
    let results = [];
    let result;
    while (i < morseCode.length) {
      result = morseCode[i].toString().split(' ').map(x => morseAlphabet[x]);
      results.push(result);
      i++;
    }
    let j = 0;
    while (results.length && j < results.length) {
        results[j].join('') + ' ';
        j++;
    }
    return results.map(item => item.join('')).join(' ');
}

decodeMorse('···−−−···')