class LinkedList:
    def __init__(self):
        self.head = None
        
    def is_empty(self):
        return self.head == None

    def size(self):
       current = self.head
       count = 0
       while current:
           count += 1
           current = current.next
       return count

    def add(self, item): 
        new_node = Node(item)
        new_node.set_next(self.head)
        self.head = new_node

    def __str__(self): #assume not empty
        result = ""
        current = self.head
        while current:
            result = result + str(current.data) + ", "
            current = current.next
        return result[:-2]
    def interleave(self, other):
        cur=self.head
        oc=other.head
        while  oc:
            pre1=oc.next
            pre=cur.next
            cur.next=oc
            cur.next.next=pre
            cur=pre
            oc=pre1