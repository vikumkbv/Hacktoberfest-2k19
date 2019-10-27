def square_sum(n):
	sum = 0
	for i in range(1,n+1):
		sum = sum + i*i
	return sum

x = int(input("Number: "))
print(square_sum(x))
