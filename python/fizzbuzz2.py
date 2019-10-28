#!/usr/bin/env python3

# FIZZBUZZ
# This program prints the numbers 1 t0 100, but for multiples
# of three , print "Fizz" instead of the number, and for multiples
# of five, print "Buzz". For numbers which  are multiples of both
# three and five, print "FizzBuzz".


def main():
    for x in range(1, 101):
        if x % 15 == 0:
            print("FizzBuzz")
        elif x % 5 == 0:
            print("Buzz")
        elif x % 3 == 0:
            print("Fizz")
        else:
            print(x)


if __name__ == "__main__":
    main()
