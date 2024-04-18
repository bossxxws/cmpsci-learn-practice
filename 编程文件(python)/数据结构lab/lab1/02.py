class Node:

  def __init__(self, init_data):
    self.data = init_data
    self.next = None

  def get_data(self):
    return self.data

  def get_next(self):
    return self.next

  def set_data(self, new_data):
    self.data = new_data

  def set_next(self, new_next):
    self.next = new_next

class FirstList:

  def __init__(self):
    self.head = None

  def is_empty(self):
    return self.head == None

  def size(self):
    curr = self.head
    count = 0
    while curr != None:
      count = count + 1
      curr = curr.get_next()
    return count

  def add(self, item):
    new_node = Node(item)
    new_node.set_next(self.head)
    self.head = new_node

  def get(self, index):
    current = self.head
    count = 0
    if index >= self.size():
      return "Index out of range"
    while current != None:
      if count == index:
        return current.get_data()
      count += 1
      current = current.get_next()

  def __str__(self):
    current = self.head
    outstr = "["
    while current != None:
      if current.get_next() == None:
        outstr = outstr + str(current.get_data())
      else:
        outstr = outstr + str(current.get_data()) + " "
      current = current.get_next()
    outstr = outstr + "]"
    return (outstr)
