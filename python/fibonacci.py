def fibonaachi(n):
	if(n == 0 or n == 1):
		return n
	return n+fibonaachi(n-1)

x = int(input())
print(fibonaachi(x))
