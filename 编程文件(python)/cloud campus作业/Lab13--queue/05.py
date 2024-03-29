def mirror_queue(a_queue):

    stack = Stack()
    temp_queue = Queue()

    while not a_queue.is_empty():
        item = a_queue.dequeue()
        stack.push(item)
        temp_queue.enqueue(item)

    while not temp_queue.is_empty():
        item = temp_queue.dequeue()
        a_queue.enqueue(item)

    while not stack.is_empty():
        item = stack.pop()
        a_queue.enqueue(item)