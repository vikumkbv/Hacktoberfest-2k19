# Run `python isIPv4.py` for a standalone IPv4 address checker.
# Import `check_IPv4` function if integrating into another program.


def check_IPv4(val):
	val_arr = val.split('.')
	if len(val_arr) != 4:
		return False

	for v in val_arr:
		if not v.isdigit():
			return False
		v = int(v)
		if not (v >= 0 and v < 256):
			return False
			
	return True

def main():
	print("Check if a given input is a valid IPv4 address. Enter q to exit.")
	print("Valid IPv4 Address: 192.168.1.13")
	print("Invalid IPv4 Address: 64.128.256.512")
	
	while True:
		try:
			val = input("Enter an address: ")
			if val.lower() == 'q':
				break
			
			if check_IPv4(val):
				print(str(val) + " is a valid IPv4 address!")
			else:
				print(str(val) + " is not a valid IPv4 address!")
		except:
			print("Unknown error occured. Terminating program.")
			break
	return 0

if __name__ == '__main__':
    main()
	
