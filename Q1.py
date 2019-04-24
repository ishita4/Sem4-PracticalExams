class LinkedList:
	def __init__(self):
		LList=[]
		self.LList=LList
		
	def display(self):
		for element in self.LList:
			print(" {}-->".format(element),end="")
		print(" NULL")
		
	def insert_at_beg(self):
		n=int(input("Enter the number to be entered:"))
		self.LList.insert(0,n)
		
	def insert_at_end(self):
		n=int(input("Enter the number to be entered:"))
		self.LList.append(n)
		
	def insert_at_position(self):
		n=int(input("Enter the number to be entered:"))
		pos=int(input("Enter the position:"))
		self.LList.insert(pos-1,n)
		
	def del_from_beg(self):
		self.LList.remove(self.LList[0])
		
	def del_from_end(self):
		print("The element popped is {}".format(self.LList.pop()))
		
	def del_at_position(self):
		pos=int(input("Enter the position:"))
		self.LList.remove(self.LList[pos-1])
		
	def del_element(self):
		n=int(input("Enter the number to be deleted:"))
		self.LList.remove(n)
		
	def search(self):
		n=int(input("Enter the number to be searched:"))
		for element in self.LList:
			if(element == n):
				print("Element found at Position ",self.LList.index(element)+1)
				break
		else:
			print("Element not found ")
			
	def replace(self):
		pos=int(input("Enter the position of number to be replaced:"))
		m=int(input("Enter the new number:"))
		self.LList.remove(self.LList[pos-1])
		self.LList.insert(pos-1,m)
	
	def forward(self):
		self.display()
		
	def reverse(self):
		self.LList=self.LList[::-1]
		self.display()
		self.LList=self.LList[::-1]
			
	def insert_after(self):
		num=int(input("Enter the number after which new element has to be entered:"))
		num2=int(input("Enter the number to be entered:"))
		self.LList.insert(self.LList.index(num)+1,num2)	#Enter element at the index + 1 position of the original number
		

obj=LinkedList()
choice=0
while choice != 14:
	print('''
        1. Display List
        2. Insert at beg
        3. Insert at end
        4. Insert at specified position
        5. Delete from beg
        6. Delete from end
        7. Delete from specified position
        8. Delete a particular element
        9. Search an element
        10. Replace element at specified index
        11. Forward Traversal
        12. Reverse Traversal
        13. Insert after an element
        14. Exit
    --------------------------------------------------- 
        ''')
	
	choice=int(input("Enter an option:"))
		
	if choice == 1:
		obj.display()	
	elif choice == 2:
		obj.insert_at_beg()
	elif choice == 3:
		obj.insert_at_end()
	elif choice == 4:
		obj.insert_at_position()
	elif choice == 5:
		obj.del_from_beg()
	elif choice == 6:
		obj.del_from_end()
	elif choice == 7:
		obj.del_at_position()
	elif choice == 8:
		obj.del_element()
	elif choice == 9:
		obj.search()
	elif choice == 10:
		obj.replace()
	elif choice == 11:
		obj.forward()
	elif choice == 12:
		obj.reverse()
	elif choice == 13:
		obj.insert_after()
	elif choice == 14:
		break
		