#Program to find factorial of a user inputed number
#Eg : factorial of 5 = 5*2*3*2*1 , factorial of 7 = 7*6*5*4*3*2*1

factorials = {0:1}

def findFactorialOf(num):
    
    # check if the number is negative, positive or zero
    if num == 0 or num == 1:
        return 1
    else:
        if num in factorials.keys():
            return factorials[num]
        else:
            print("Factorial of {} not found. Adding to factorials dictionary...".format(num))
            factorials[num] = findFactorialOf(num - 1) * num
            return factorials[num]



userInput = input("Enter a number or (q)uit: ")

while userInput != "q":
    factorialNum = int(userInput)
    if factorialNum < 0:
        print("Negative numbers don't have factorial!")
    else:
        print("The factorial of {} is {}".format(factorialNum, findFactorialOf(factorialNum)))
    userInput = input("Enter a number or (q)uit: ")




