a=int(input())
b = a // 100
c = (a - b * 100) // 10
d = a - b * 100 - c * 10
e = b ** 3 + c ** 3 + d ** 3
if a >= 1000:
    print("Out scope")
if a < 1000 and a == e:
    print("Yes")
if a < 1000 and (a > e or a < e)  :
    print("No")


