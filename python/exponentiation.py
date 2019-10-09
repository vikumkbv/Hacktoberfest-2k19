def exponentiation(bas,exp):
	if(exp == 0):
		return 1
	if(exp == 1):
		return bas
	if(exp%2==0):
		return exponentiation(bas*bas,exp//2)
	else:
		return bas*exponentiation(bas*bas,(exp-1)//2)


x = int(input())
y = int(input())

print(exponentiation(x,y))
