from math import sqrt
def prime(n) :
    for i in range(2,int(sqrt(n)+1)):
        if n % i ==0:
            return False
    return True
def countprime(N) :
    if N < 3 :
        return 0
    else:
        cou = 1
        for i in range(3,N,2):
            if prime(i):
                cou += 1
    return cou
x = int(input())
print(countprime(x))

