n = int(input())
p2 = 1
while n >= p2:
    p2 = p2 * 2
p2 = p2 // 2
while n > 0 :
    if n > p2:
        print(1,end="")
        n = n - p2
    elif n == p2:
        print(1,end="")
        p2 = p2 // 2
        while p2 > 0:
            print(0,end="")
            p2 = p2 // 2
        break
    else:
        print(0,end = "")
    p2 = p2 // 2