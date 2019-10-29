#Program to find factorial of a user inputed number
#Eg : factorial of 5 = 5*2*3*2*1 , factorial of 7 = 7*6*5*4*3*2*1

userInput = input("Enter a number or (q)uit: ")

factorial = 1

while userInput != "q":

    num = int(userInput)
    # check if the number is negative, positive or zero
    if num < 0:
       print("Negative numbers don't have factorial!")
    elif num == 0:
       print("The factorial of 0 is 1")
    else:
       for i in range(1,num + 1):
           factorial = factorial*i
       print("The factorial of", num, "is", factorial)
    userInput = input("Enter a number or (q)uit: ")
