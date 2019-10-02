
import random as rd
a=['Rock','Paper','Scissor']

user=int(input("Enter 0 for Rock,1 for Paper,2 for Scissor\n"))
print(a[user])

Computer=rd.choice(a)

print("Player vs Computer")
print(f"{a[user]} vs {Computer}")

if a[user] =='Rock'and Computer=='Scissor':
    print("Player wins")
elif a[user] =='Rock'and Computer=='Rock':
    print("Its a Tie")
elif a[user] =='Rock'and Computer=='Paper':
    print("Computer wins")
elif a[user] =='Paper'and Computer=='Paper':
    print("It's a Tie")
elif a[user] =='Paper'and Computer=='Rock':
    print("Computer wins") 
elif a[user] =='Paper'and Computer=='Scissor':
    print("Player wins") 
elif a[user] =='Scissor'and Computer=='Paper':
    print("Player wins") 
elif a[user] =='Scissor'and Computer=='Rock':
    print("Computer wins") 
else:
    print("It's a Tie")

