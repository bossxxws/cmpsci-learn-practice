def reverse_sentence(sentence):
    words = sentence.split()  
    stack = Stack()  


    for word in words:
        stack.push(word)

    reversed_sentence = ""

    while not stack.is_empty():
        reversed_sentence += stack.pop() + " "

    return reversed_sentence.strip() 


print(reverse_sentence('hello world'))
print(reverse_sentence('Python programming is fun '))