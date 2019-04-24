from tkinter import *
def reset():
	pass
    
def add():
    tempList=[]
    tempList.append(name.get())
	tempList.append(phone.get())
    person_list.append(tempList)
	
def delete():
	pass
    
#----For update user will enter name and then
def update():
	pass

def show():	
	for i in range(person_list):
		text.insert(END,"{}\t{}".format(i[0],i[1]))

person_list = [] # Initially empty phone list

root = Tk()

root.geometry('400x400')
root.title('PHONE LIST')
root.resizable(width=False,height=False)
root.configure(background='grey')
#----For extracting value from entry----#
name = StringVar()
phone = StringVar()

#----For displaying Phone list------#
ans = StringVar()
text = Text(root)
text.place(x=60,y=200,width=280,height=180)


#-----Creating label and entry-----#
Label(root,text='Name : ',).grid(row=0,column=0,padx=5,pady=15)
Entry(root,textvariable=name).grid(row=0,column=1,padx=5,pady=15)

Label(root,text='Phone : ',).grid(row=1,column=0,padx=5,pady=15)
Entry(root,textvariable=phone).grid(row=1,column=1,padx=5,pady=15)

Button(root,text='ADD',command=add).place(x=10,y=150,width=80)
Button(root,text='DELETE',command=delete).place(x=110,y=150,width=80)
Button(root,text='UPDATE',command=update).place(x=210,y=150,width=80)
Button(root,text='SHOW',command=show).place(x=310,y=150,width=80)


root.mainloop()
