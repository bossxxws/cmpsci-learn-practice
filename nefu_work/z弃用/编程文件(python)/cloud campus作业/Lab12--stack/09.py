postfix_stack = Stack()  

postfix_expression = "3 4 * 6 / 3 +"
tokens = postfix_expression.split()

for token in tokens:
    if token.isdigit():  
        postfix_stack.push(float(token))
    else:  
        if postfix_stack.size() < 2:
            print("Error: Not enough operands for operator.")
            break
        operand2 = postfix_stack.pop()
        operand1 = postfix_stack.pop()
        result = None
        if token == '+':
            result = operand1 + operand2
        elif token == '-':
            result = operand1 - operand2
        elif token == '*':
            result = operand1 * operand2
        elif token == '/':
            result = operand1 / operand2
        else:
            print("Error: Invalid operator.")
            break
        postfix_stack.push(result)

if postfix_stack.size() == 1:
    print(postfix_stack.pop())
else:
    print("Error: Invalid expression.")