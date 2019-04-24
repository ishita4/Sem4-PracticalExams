from tkinter import *

def isPalindrome():
	str=string.get().upper()
	solutionField.place(x=50,y=300,height=60,width=200)
	strRev=str[::-1]
	
	if(str == strRev):
		solutionString.set("{} is a Palindrome!!".format(str))
	else:
		solutionString.set("{} is a not a Palindrome".format(str))
		
def reset():
	solutionField.place_forget()

root=Tk()
root.title("Palindrome")
root.geometry("350x400")

l=Label(root, text="Enter String:")
#l.grid(row=0,column=0)
l.place(x=20,y=20)

string=StringVar()
e=Entry(root, textvariable=string)
#l.grid(row=0,column=0)
e.place(x=100,y=20)

palindromeButton=Button(root,text="Is Palindrome",bg="grey",command=isPalindrome)
palindromeButton.place(x=30,y=150,width=100,height=40)

reset=Button(root,text="Reset",bg="grey",width=10,height=2,command=reset)
reset.place(x=150,y=150)

exit=Button(root,text="Exit",bg="grey",width=10,height=2,command=quit)
exit.place(x=250,y=150)

solutionString=StringVar()
solutionField=Entry(root,textvariable=solutionString,state=DISABLED)


root.mainloop()