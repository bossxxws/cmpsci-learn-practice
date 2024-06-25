def balanced_brackets(text):
    stack = Stack()  # Create a stack object

    for char in text:
        if char == '(' or char == '<':
            stack.push(char)
        elif char == ')' or char == '>':
            if stack.is_empty():
                return False  # Unbalanced closing bracket without a corresponding opening bracket
            opening_bracket = stack.pop()
            if (char == ')' and opening_bracket != '(') or (char == '>' and opening_bracket != '<'):
                return False  # Mismatched opening and closing brackets

    return stack.is_empty()  # Check if there are any unclosed opening brackets

# Example usage:
print(balanced_brackets('(<x>)(())()'))  # True
print(balanced_brackets('x(y)z'))  # True
print(balanced_brackets('(<x)>(())()'))  # False
print(balanced_brackets('x<y)(>z'))  # False