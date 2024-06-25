class Node:
    
    def __init__(self, data):
        self.data = data
        self.next = None

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_data(self, new_data):
        self.data = new_data

    def set_next(self, new_next):
        self.next = new_next
class LinkedList:

    def __init__(self):
        self.head = None
        self.count = 0

    def is_empty(self):
        return self.count == 0

    def size(self):
        return self.count
    
    def add(self, item):
        if not self.head:
            self.head=Node(item)
        else:
            curr=self.head
            while(curr.next and curr.data<item):
                if curr.next.data<item:
                    curr=curr.next
                else:
                    break
            if not curr.next:
                curr.next=Node(item)
            else:
                newnode=Node(item)
                newnode.next=curr.next
                curr.next=newnode

    def search(self, item):
        curr = self.head 
        while curr != None:
            if curr.get_data() == item:
                return True
            else:
                curr = curr.get_next()
        return False

    def remove(self, item):
        found = False
        current = self.head
        previous = None
        while current != None and not found:
            if current.get_data() == item:
                found = True
            else:
                previous = current
                current = current.get_next()
        if found:
            if previous == None:
                self.head = current.get_next()
            else:
                previous.set_next(current.get_next())
            self.count -= 1
            
    def __str__(self):
        result = ''
        current = self.head    
        while current:
            result += str(current.get_data()) + ', '
            current = current.get_next()

        return result[:-2]    

    def get_total(self):
        total = 0
        current = self.head    
        while current:
            total += current.get_data()
            current = current.get_next()

        return total    

    def concat(self, other):
        # find last node in list
        curr = self.head
        while curr.next:
            curr = curr.next
            
        # connect to other list
        curr.set_next(other.head)
        self.count += other.count
l = LinkedList()
l.add(2)
l.add(3)
l.add(4)
l.add(10)
print(l)