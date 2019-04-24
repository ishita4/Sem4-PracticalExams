from tkinter import *

root=Tk()
root.title("Sample")
root.geometry('400x400')

expr=StringVar()
e=Entry(root, textvariable=expr)
e.place(x=20,y=20,height=30,width=360)

Button(root,text="1",command=lambda:expr.set(expr.get()+'1')).place(x=20,y=80,height=40,width=50)
Button(root,text="2",command=lambda:expr.set(expr.get()+'2')).place(x=100,y=80,height=40,width=50)
Button(root,text="3",command=lambda:expr.set(expr.get()+'3')).place(x=180,y=80,height=40,width=50)
Button(root,text="+",command=lambda:expr.set(expr.get()+'+')).place(x=260,y=80,height=40,width=50)
Button(root,text="-",command=lambda:expr.set(expr.get()+'-')).place(x=340,y=80,height=40,width=50)

Button(root,text="4",command=lambda:expr.set(expr.get()+'4')).place(x=20,y=160,height=40,width=50)
Button(root,text="5",command=lambda:expr.set(expr.get()+'5')).place(x=100,y=160,height=40,width=50)
Button(root,text="6",command=lambda:expr.set(expr.get()+'6')).place(x=180,y=160,height=40,width=50)
Button(root,text="*",command=lambda:expr.set(expr.get()+'*')).place(x=260,y=160,height=40,width=50)
Button(root,text="/",command=lambda:expr.set(expr.get()+'/')).place(x=340,y=160,height=40,width=50)

Button(root,text="7",command=lambda:expr.set(expr.get()+'7')).place(x=20,y=240,height=40,width=50)
Button(root,text="8",command=lambda:expr.set(expr.get()+'8')).place(x=100,y=240,height=40,width=50)
Button(root,text="9",command=lambda:expr.set(expr.get()+'9')).place(x=180,y=240,height=40,width=50)
Button(root,text="(",command=lambda:expr.set(expr.get()+'(')).place(x=260,y=240,height=40,width=50)
Button(root,text=")",command=lambda:expr.set(expr.get()+')')).place(x=340,y=240,height=40,width=50)

Button(root,text="0",command=lambda:expr.set(expr.get()+'0')).place(x=20,y=320,height=40,width=130)
Button(root,text=".",command=lambda:expr.set(expr.get()+'.')).place(x=180,y=320,height=40,width=50)
Button(root,text="=",command=lambda:expr.set(eval(expr.get()))).place(x=260,y=320,height=40,width=130)

root.configure(bg="grey")
root.mainloop()
