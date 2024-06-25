class Stack:
    def __init__(self):
        self.stack = []
    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        else:
            raise IndexError("Stack is empty")
    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        else:
            raise IndexError("Stack is empty")

    def is_empty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)
def valid(tar):
    openlist=["{","(","["]
    closelist=["}",")","]"]
    s=Stack()
    l = len(tar)
    for i in range(l):
        if tar[i] in openlist:
            s.push(tar[i])
        elif tar[i] in closelist :
            s.pop()
        elif tar[i] in closelist:
            s.push(tar[i])
    return s.is_empty()
ta="{{}}"
print(valid(ta))





stack1=Stack()
stack1.push(1)
stack1.push(2)
sum=0
for i in range(stack1.size()):
    sum = sum+stack1.pop()
print(sum)
K = not (stack1.is_empty())
print(K)


        
    
