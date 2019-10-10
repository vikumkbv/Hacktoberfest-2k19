class Node:

	def __init__(self,data,left,right):
		self.data = data
		self.left = left
		self.right = right

class BST:
	
	def __init__(self,data):
		self.root = Node(data,None,None)

	def insert(self,root,data):
		if root.data<=data and root.left == None:
			root.left = Node(data,None,None)
			return
		if root.data>data and root.right == None:
			root.right = Node(data,None,None)
			return
		if root.data<=data:
			self.insert(root.left,data)
		else:
			self.insert(root.right,data)
	
	def print_tree(self,root):
		if root == None:
			return
		self.print_tree(root.left)
		print(root.data)
		self.print_tree(root.right)

x = int(input())
y = int(input())
bst = BST(y)
i = 0
while(i<x-1):
	y = int(input())
	bst.insert(bst.root,y)
	i = i+1
bst.print_tree(bst.root)