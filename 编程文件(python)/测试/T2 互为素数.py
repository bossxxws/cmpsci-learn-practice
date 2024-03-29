n = int(input())
for i in range(1,n+1):
    for j in range(1,n+1):
        if i > j :
            minv = j
        else:
            minv = j
        k = minv
        while k > 1:
            if i % k == 0 and j % k == 0 :
                break
            k = k - 1
        if k == 1:
            print("*",end="")
        else:
            print("#",end="")
    print()