
def is_palindrome(word):
    # Create a stack and a queue
    stack = Stack()
    queue = Queue()


    for char in word:
        stack.push(char)
        queue.enqueue(char)

    while not queue.is_empty():
        if queue.dequeue() != stack.pop():
            return False

    return True