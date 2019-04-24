class Duck:
    def talk(self):
        print("Quack,Quack")

class Man:
    def talk(self):
        print("Hello, Hi")

class Dog:
    def bark(self):
        print("Bow,Wow")

def can_talk(object):
    try:
        object.talk()
    except AttributeError as ae:
        print(ae)

d=Duck()
m=Man()
do=Dog()

can_talk(d)
can_talk(m)
can_talk(do)
