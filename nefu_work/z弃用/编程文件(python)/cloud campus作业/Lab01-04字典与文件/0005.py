rows = int(input("Enter number of rows: "))
print("*" * rows)
for i in range(rows - 2):
    print("*", end="")
    for j in range(rows - 2):
        if j == i or j == rows - 3 - i:
            print("*", end="")
        else:
            print(" ", end="")
    print("*")
print("*" * rows)