lie = int(input("Enter number of rows: "))
for i in range(1,lie+1):
    if i != 1 :
        print("")
    for j in range(1,i+1):
        print(f"{j} ",end="")  