class Car():
    def __init__(self) -> None:
        self.carlist=[]
    def usef(self,func):
        return func(self.carlist)
def func(li):
    if  len(li)>0:
        li.pop()
    else:
        print("is already empty")
car1=Car()
car1.usef(func)

