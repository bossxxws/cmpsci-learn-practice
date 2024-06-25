def evaluate_postfix(postfix_list):
    stack = Stack()

    for token in postfix_list:
        if token.isdigit():  # Operand, push onto stack
            stack.push(int(token))
        else:  # Operator
            if stack.size() < 2:
                raise ValueError("Not enough operands for operator.")
            operand2 = stack.pop()
            operand1 = stack.pop()
            result = compute(operand1, operand2, token)
            stack.push(result)

    if stack.size() == 1:
        return stack.pop()
    else:
        raise ValueError("Invalid expression.")


def compute(operand1, operand2, operator):
    if operator == '+':
        return operand1 + operand2
    elif operator == '-':
        return operand1 - operand2
    elif operator == '*':
        return operand1 * operand2
    elif operator == '/':
        return operand1 // operand2
    elif operator == '^':
        return operand1 ** operand2
    elif operator == '%':
        return operand1 % operand2
    else:
        raise ValueError("Invalid operator.")


