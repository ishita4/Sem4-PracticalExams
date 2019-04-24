import re

f=open("Regex.txt","w+")
str="""This project is assign to Mr. Nageswaran Rao at nageswaran.rao@abc.net,and in case of any queries , you can contact Mr. Mahesh at mahesh.k@gmail.com 
	or Ms. Veena Sharma at sveen13@pqr.org, who would be assistant project co-ordinators."""
	
f.write(str)
f.seek(0,0)

str1=f.read()
result=re.findall(r'\S+@\S+',str1)

if(len(result)>0):
	print(result)
else:
	print("No email Id present")

f.close()