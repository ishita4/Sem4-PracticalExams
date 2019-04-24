class Stack:
	def __init__(self):
		stack=[]
		self.stack=stack
		
	def push(self):
		self.stack.append(int(input("Enter the value to be pushed")))
		
	def pop(self):
		if len(self.stack) != 0:
			print("The value popped is: ", self.stack.pop())
		else:
			print("Underflow")
		
	def top(self):
		print("The top of the stack is: ", self.stack[len(self.stack)-1])
		
	def search(self):
		n=int(input("Enter the number to be searched:"))
		for element in self.stack:
			if(element == n):
				print("Element found at Position ",self.stack.index(element)+1)
				break
		else:
			print("Element not found ")
			
	def display(self):
		print("Stack:")
		for element in self.stack:
			print(element,end=" ")

obj=Stack()
choice=0
while choice != 6:
	print('''
        1. Push
        2. Pop
        3. Top of the Stack
        4. Search
        5. Display
        6. Exit
    --------------------------------------------------- 
        ''')
	
	choice=int(input("Enter an option:"))
		
	if choice == 1:
		obj.push()	
	elif choice == 2:
		obj.pop()
	elif choice == 3:
		obj.top()
	elif choice == 4:
		obj.search()
	elif choice == 5:
		obj.display()
	elif choice == 6:
		break