x = float(input())
n = 1
sinx = 0
while True:
    facn = 1
    for i in range (1,n+1):
        facn = facn * i
    if x ** n /facn > 1e-10 :
        if(n-1) % 4 == 0:
            sinx =sinx + (x ** n / facn)
        else:
            sinx = sinx - (x**n/facn)
    else:
        break
    n = n + 2
print(round(sinx,2))  
