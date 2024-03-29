def remove_negatives(stack):
    s=Stack()
    while not stack.is_empty():
        if stack.peek()>=0 :
            s.push(stack.peek())
        stack.pop()
    while not s.is_empty():
        stack.push(s.pop())
    return stack