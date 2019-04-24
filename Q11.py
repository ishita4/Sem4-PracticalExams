import pickle

class Patient:
	no_of_patients=0
	
	def __init__(self,pid,name,wardno,age):
		self.pid=pid
		self.name=name
		self.wardno=wardno
		self.age=age
		
	def set_details(self,gender,bloodgroup):
		self.gender=gender
		self.bloodgroup=bloodgroup
		
	def display(self):
		if self.gender == 'Male':
			print("{}\t{}\t{}\t{}\t{}\t{}\n".format(self.name,self.pid,self.wardno, self.age, self.gender, self.bloodgroup))
		
	@classmethod
	def set_no_of_patient(cls):
		cls.no_of_patients += 1
		
choice=0
patientList=[]
print('''
    1. Insert an patient to the list
    2. Save details to file
    3. Display Male patients
    4. Exit
    ''')
	
while(True):
    
	choice=int(input("Enter choice: "))
	if(choice == 1):
		id=int(input("Enter PID: "))
		name=input("Enter name: ")
		wardno=input("Enter Ward no: ")
		age=int(input("Enter age: "))
		gender=input("Enter gender: ")
		bg=input("Enter blood group: ")

		patientList.append(Patient(id,name,wardno,age))
		patientList[-1].set_details(gender,bg)
		Patient.set_no_of_patient();
		
	elif choice == 2:
		f=open("Patient.dat",'wb')
		for i in range(Patient.no_of_patients):
			print("pickle dump")
			pickle.dump(patientList[i],f)
		f.close()
		
	elif choice == 3:
		newList=[]
		f=open("Patient.dat",'rb')
		print("Name\tPID\tWard No\tAge\tGender\tBlood Group\n")
		for i in range(Patient.no_of_patients):
			newList.append(pickle.load(f))
			newList[i].display()	
		f.close()
			
	elif choice == 4:
		break
		
