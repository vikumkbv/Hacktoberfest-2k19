function fibonacci (number) {
    var varFibonacci = [0, 1];
  
    if (number <= 2) return 1;
    
    for (var i = 2; i <= number; i++) {
        varFibonacci[i] = varFibonacci[i-1] + varFibonacci[i-2];
    }
  
    return varFibonacci[number];
}