class LinkedList:
    def __init__(self):
        self.head = None
    def __iter__(self):
        return LinkedList(self.head)
class Linklistiterators:
    def __iter__(self):
        self.current = self.head
        return self
    def __next__(self):
        if self.current is None:
            raise StopIteration
        else:
            data = self.current.get_data()
            self.current = self.current.get_next()
            return data