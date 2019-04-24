from tkinter import *
import pickle

class Detail(object):
    def __init__(self,first_name,last_name,languages,country):
        self.first_name = first_name
        self.last_name = last_name
        self.languages = languages
        self.country = country

    def display_detail(self):
        print('DETAILS ARE : ')
        print("First name={}\nLast name={}\nLanguages={}\nCountry={}\n".format(self.first_name,self.last_name,self.languages,self.country))
		

def saveDetails():
	f_name=fname.get()
	l_name=lname.get()
	langList=[]
	if var1:
		langList.append('Java')
	if var2:
		langList.append('Python')

	cntry=country.get()
	
	root.destroy()
	
	newRoot=Tk()
	newRoot.title("Details")
	newRoot.geometry("400x400")
	
	my_detail =  f'''
        
        First-Name = {f_name}
        Last-Name  = {l_name}
        Languages  = {langList}
        Country    = {cntry}
    
    ''' 
	text=Text(newRoot)
	text.insert(END,my_detail)
	text.place(x=20,y=50,width=300,height=200)
	newRoot.mainloop()
	#print(f_name,l_name,langList,cntry)
	
	


root=Tk()
root.title("Form")
root.geometry("400x400")


Label(root,text="First Name").place(x=50,y=50,width=100,height=40)
Label(root,text="Last Name").place(x=50,y=130,width=100,height=40)
Label(root,text="Languages").place(x=50,y=210,width=100,height=40)
Label(root,text="Country").place(x=50,y=290,width=100,height=40)

fname=StringVar()
lname=StringVar()
Entry(root,textvariable=fname).place(x=200,y=50,width=150,height=30)
Entry(root,textvariable=lname).place(x=200,y=130,width=150,height=30)

var1=IntVar()
Checkbutton(root,text="Java",variable=var1,onvalue=1,offvalue=0).place(x=200,y=210)

var2=IntVar()
Checkbutton(root,text="Python",variable=var2,onvalue=1,offvalue=0).place(x=270,y=210)

country=StringVar()
lst=['India','Japan','China']
OptionMenu(root,country,*lst).place(x=200,y=290,width=100)

Button(root,text="Submit",command=saveDetails).place(x=100,y=350,width=100,height=40)

root.mainloop()