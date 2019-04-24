class Queue:
	def __init__(self):
		queue=[]
		self.queue=queue
		
	def insert(self):
		self.queue.append(int(input("Enter the value to be enqueued")))
		
	def remove(self):
		if len(self.queue) != 0:
			print("The value dequeued is: ", self.queue.pop(0))
		else:
			print("Underflow")
		
	def search(self):
		n=int(input("Enter the number to be searched:"))
		for element in self.queue:
			if(element == n):
				print("Element found at Position ",self.queue.index(element)+1)
				break
		else:
			print("Element not found ")
			
	def display(self):
		print("Queue:")
		for element in self.queue:
			print(element,end=" ")

obj=Queue()
choice=0
while choice != 5:
	print('''
        1. Insert
        2. Remove
        3. Search 
	4. Display
        5. Exit
    --------------------------------------------------- 
        ''')
	
	choice=int(input("Enter an option:"))
		
	if choice == 1:
		obj.insert()	
	elif choice == 2:
		obj.remove()
	elif choice == 3:
		obj.search()
	elif choice == 4:
		obj.display()
	elif choice == 5:
		break
