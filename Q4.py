class Employee:
	empcount=0
	
	def __init__(self,id,department,experience,salary):
		self.id=id
		self.department=department
		self.experience=experience
		self.salary=salary
		
	def set_name(self,name):
		self.name=name
		
	def display(self):
			print("{}\t{}\t{}\t{}\t{}\n".format(self.name,self.id,self.department,self.experience,self.salary))
		
	@classmethod
	def set_emp_count(cls):
		cls.empcount +=1
		

choice=0
empList=[]
print('''
    1. Insert an employee to the list
    2. Display list of employees
    3. Display total number of employees
    4. Display Avg salary
    5. Exit
    ''')

while(True):
    
	choice=int(input("Enter choice: "))
	if(choice == 1):
		id=int(input("Enter ID: "))
		dept=input("Enter dept: ")
		exp=float(input("Enter exp: "))
		sal=float(input("Enter salary: "))
		name=input("Enter name: ")
		empList.append(Employee(id,dept,exp,sal))
		empList[-1].set_name(name)
		Employee.set_emp_count()
		
	elif choice == 2:
		print("Name\tId\tDept\tExp\tSalary\n")
		for i in range(Employee.empcount):
			empList[i].display()
			
	elif choice == 3:
		print("Total number of employees are:", Employee.empcount)
		
	elif choice == 4:
		total=0
		for i in range(len(empList)):
			total = total + empList[i].salary
		print("Average salary is:", total/Employee.empcount)
			
	elif choice == 5:
		break