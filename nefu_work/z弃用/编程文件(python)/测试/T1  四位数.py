n = input("n=")
n = int(n)
a = n // 1000
b = (n - (a * 1000)) // 100
c = (n - (a * 1000 + b * 100)) // 10
d = n - (a * 1000 + b * 100 + c * 10)
result = a + b + c + d
print("result=",result)
 
