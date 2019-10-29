def fibonacci(n):
	if(n == 0 or n == 1):
		return n
	return n+fibonacci(n-1)

x = int(input("Enter a positive number, or quit by entering a negative number"))

while x >= 0:
    print(fibonacci(x))
    x = int(input())
