class Numbers:
    def __init__(self,low,high):
        self.low=low
        self.high=high
    def __iter__(self):
        return NumbersIterater(self.low,self.high)#call numbersiterators' function
class NumbersIterater:
    def __init__(self,low,high):
        self.cur=low
        self.high=high
    def __next__(self):
        cur=self.cur#use python to write a linklist's iterator

ex=[1,2,3,4,5]
it = ex.__iter__()
print(next(it))
print(next(it))
print(it.__next__)
print(next(it))
print(next(it))
print(next(it))
