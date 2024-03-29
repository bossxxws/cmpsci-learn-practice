import math
a = input("a=")
b = input("b=")
c = input("c=") 
a=int(a)
b=int(b)
c=int(c)
temp = b ** 2 - 4*a*c
if temp >= 0 :
    print("x1 = ",(-b + math.sqrt(temp)) / (2 * a),"x2 = ",(-b - math.sqrt(temp)) / (2 * a))
elif temp <0  :
    print("no solution")
    


    
