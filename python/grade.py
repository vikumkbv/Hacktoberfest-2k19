from math import *
grade=input("Enter your marks between 0 and 100")
if grade>100:
	print "cannot exceed 100"
elif grade<0:
	print "cannot be negative"
elif grade>=75:
	print "A grade"
elif grade>=60:
	print "B grade"
elif grade>=40:
	print "C grade"
else:
	print "fail"
#Enter your marks between 0 and 100 75
#A grade

#Enter your marks between 0 and 100 55
#C grade

#Enter your marks between 0 and 100 40
#C grade
 
#Enter your marks between 0 and 100 60
#B grade
 
#Enter your marks between 0 and 100 35
#fail
