class SquareNumber:
    def __init__(self, count=5):
        self.__count = count

    def __iter__(self):
        return SquareNumberIterator(self.__count)
class SquareNumberIterator:
    def __init__(self, count):
        self.__current = 1
        self.__count = count

    def __next__(self):
        if self.__current <= self.__count:
            square = self.__current ** 2
            self.__current += 1
            return square
        else:
            raise StopIteration
for number in SquareNumber(5):
    print(number)

            
        
        