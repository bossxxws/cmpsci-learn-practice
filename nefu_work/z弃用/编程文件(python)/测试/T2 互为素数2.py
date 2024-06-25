n = int(input())
for i in range(1,n+1):
    for j in range (1, n + 1):
        d1 = i
        d2 = j  
        r = d1 % d2
        while r != 0 :
            d1 , d2 = d2 , r
            r = d1 % d2
        if d2 == 1 :
            print("*",end = "")
        else:
            print("#",end = "")
    print()