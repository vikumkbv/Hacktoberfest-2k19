#Program to find factorial of a user inputed number
#Eg : factorial of 5 = 5*2*3*2*1 , factorial of 7 = 7*6*5*4*3*2*1

userInput = input("Enter a number or (q)uit: ")

factorials = {0:1, 1:1}

def factorialOf(num):
    if num in factorials.keys():
        return factorials[num]
    else:
        factorials[num] = factorialOf(num - 1) * num
        return factorials[num]

while userInput != "q":

    num = int(userInput)
    # check if the number is negative, positive or zero
    if num < 0:
       print("ValueError: negative number given. Please enter a positive number.")
    else:
       print("The factorial of {} is {}".format(num, factorialOf(num)))
    userInput = input("Enter a positive number or (q)uit: ")
