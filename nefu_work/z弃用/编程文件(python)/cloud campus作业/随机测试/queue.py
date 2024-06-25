class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
        else:
            print("queue is empty")
    def peek(self):
        print(self.items[0])
    def size(self):
        return len(self.items)
q = Queue()
q.enqueue(0)
q.enqueue(1)
q.peek()
q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()