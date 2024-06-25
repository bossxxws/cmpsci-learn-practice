class Squares:
    def __init__(self, n):
        self.n = n

    def __iter__(self):
        return itersq(self.n)
class itersq:
    def __init__(self, n):
        self.n = n
        self.cur = 1
    def __next__(self):
        if self.cur <= self.n:
            sq = self.cur ** 2
            self.cur += 1
            return sq
        else:
            raise StopIteration
su=Squares(19)
for i in su:
    print(i,end=" ")