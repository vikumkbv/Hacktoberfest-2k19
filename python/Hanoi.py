"""
This algorithm solves the tower of hanoi problem using recursion



          ||            ||            ||
          ||            ||            ||
       ===||===         ||            ||
       ===||===         ||            ||
          ||            ||            ||
     =====||=====       ||            ||
     =====||=====       ||            ||
          ||            ||            ||
   =======||=======     ||            ||
   =======||=======     ||            ||
==============================================
          A             B              C


"""

def hanoi(num, fromm, to, through):
	if num == 0:
		return
	hanoi(num - 1, fromm, through, to)
	print(f"Move from {fromm} to {to}")
	hanoi(num - 1, through, to, fromm)
  
  
"""
Example:
  hanoi(3, "A", "C", "B")
"""
