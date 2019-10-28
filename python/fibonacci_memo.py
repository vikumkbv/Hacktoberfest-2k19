#!/usr/bin/env python3

# Get the nth fibonacci using memiozation.
# The larger the integer , the longer it will take to compute the nth fibonacci

fib_memo = dict()


def main():
    """This function will ask the user for an integer input , initialize the 
       fibonacci dictionary , determine the nth fibonacci , and print the digits
    """
    int_input = int(input('Enter an integer to get x digit of fibonacci: '))
    init_fib_memo()
    fib(int_input)
    print(list(fib_memo.values()))


def init_fib_memo():
    """This initializes the dictionary"""
    fib_memo[0] = 0
    fib_memo[1] = 1


def fib(int_input):
    """This is the recursion function to get the fibonacci digit   """

    if int_input not in fib_memo:
        fib_memo[int_input] = fib(int_input - 1) + fib(int_input - 2)
    return fib_memo[int_input]


if __name__ == '__main__':
    main()
