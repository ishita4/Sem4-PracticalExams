class X(object):
	def __init__(self):
		print("X Class Constructor")
		super().__init__()
		
class Y(object):
	def __init__(self):
		print("Y Class Constructor")
		super().__init__()
		
class Z(object):
	def __init__(self):
		print("Z Class Constructor")
		super().__init__()
		
class A(X,Y):
	def __init__(self):
		print("A Class Constructor")
		super().__init__()
		
class B(Y,Z):
	def __init__(self):
		print("B Class Constructor")
		super().__init__()
		
class M(A,B,Z):
	def __init__(self):
		print("M Class Constructor")
		super().__init__()
		
obj=M()
print(M.mro())

