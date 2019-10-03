# Run `python isPrime.py` for a standalone prime number checker.
# Import `check_prime` function if integrating into another program.


from math import sqrt


def check_prime(val):
	if val <= 1:
		return False
	else:
		for i in range(2, int(sqrt(val)) + 1):
			if val % i == 0:
				return False
		return True	

def main():
	print("Check if a given integer is a prime number. Enter q to exit.")
	
	while True:
		try:
			val = input("Enter an integer: ")
			if val.lower() == 'q':
				break
			val = int(val)
			
			if check_prime(val):
				print(str(val) + " is a prime number!")
			else:
				print(str(val) + " is not a prime number!")
		except ValueError:
			print("That's not an integer! :(")
		except:
			print("Unknown error occured. Terminating program.")
			break
	return 0

if __name__ == '__main__':
    main()
	