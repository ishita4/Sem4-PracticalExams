f=f=open("Dummy.txt","r")

wc=0
cc=0
lc=0
for line in f:
	lc += 1
	words=line.split()
	
	wc= wc + len(words)
	cc= cc + len(line)
	
f2=open("NewDummy.txt","w")
str=f.read()
f2.write(str)
f2.close()

print("Done")

	
print(lc)
print(wc)
print(cc)

f.close()