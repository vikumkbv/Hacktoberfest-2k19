class Node:
	def __init__(self,data,next):
		self.data = data
		self.next = next

class LinkedList:
	def __init__(self):
		self.head = Node(0,None)
		self.current = self.head
	def addObject(self,data):
		self.current.next = Node(data,None)
		self.current = self.current.next
	def printList(self):
		n = self.head
		while(n != None):
			print(n.data)
			n = n.next



n = int(input())
i = 0
l = LinkedList()
while(i<n):
	x = int(input())
	l.addObject(x)
	i = i+1
l.printList()

