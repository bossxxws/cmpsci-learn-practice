a = int(input())
b = int(input())
a1, b1 = a, b 
K = a1 % b1
while K != 0:
   a1, b1 = b1 , K
   K = a1 % b1
print(str(b1)+" "+str(round(a * b / b1)))


