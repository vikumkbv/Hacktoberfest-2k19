fibonacciNums = {0:0, 1:1}

def fibonacci(n):
    if n in fibonacciNums.keys():
        return fibonacciNums[n]
    else:
        fibonacciNums[n] = fibonacci(n-1) + fibonacci(n-2)
        return fibonacciNums[n]

x = int(input("Enter a positive number, or quit by entering a negative number: "))

while x >= 0:
    print("{}th fibonacci is {}".format(x, fibonacci(x)))
    x = int(input("Enter a positive number, or quit by entering a negative number: "))
