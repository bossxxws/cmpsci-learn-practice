for value in range(1, 5):
    print(value)
print("\n")
for value in range(1, 6):
    print(value)
numbers =list(range(1, 7))
print(numbers)
numbers_1 = list(range(2, 13, 3))
print(numbers_1)
#便捷的使用range
#method_1
squares = []
for value in range(1,11):
    square = value ** 2
    squares.append(square)
print(squares)    
#method_2 不使用临时变量square
squares = []
for value in range(1,11):
    squares.append(value ** 2)
print(squares)     