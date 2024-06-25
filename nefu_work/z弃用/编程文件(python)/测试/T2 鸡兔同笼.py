head = int(input())
foot = int(input())
if foot == head * 2:
    print("only have chicken:",head)
if foot == head * 4:
    print("only have rabbit:",head)
if head * 4 < foot:
    print("No solution")
else:
    for x in range(1,head):
        y = head - x
        if 2 * x + 4 * y == foot:
            print("rabbit:",y,"chicken:",x) 
    

  



