def jump_queue(queue, value):
    q=Queue()
    c=False
    while not queue.is_empty():
        if queue.peek()!=value or c:
            q.enqueue(queue.dequeue())
        else:
            c=True
            queue.dequeue()
    if c:
        queue.enqueue(value)
    while not q.is_empty():
        queue.enqueue(q.dequeue())

    return queue