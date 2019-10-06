# Run `python findGCD.py` for a standalone GCD finder.
# Import `find_gcd` function if integrating into another program.


def find_gcd(a, b):
    if (b == 0): 
        return a 
    else: 
        return find_gcd(b, a%b) 

def main():
    print("Find the Greatest Common Denominator (GCD) of two given integers!")
    try:
        a = int(input("Enter your first integer: "))
        b = int(input("Enter your second integer: "))
        c = find_gcd(a, b)
        print("The GCD of", a, "and", b, "is", c)
        return 0
    except ValueError:
        print("Those are not two integers! :(")
        return -1

if __name__ == '__main__':
    main()
