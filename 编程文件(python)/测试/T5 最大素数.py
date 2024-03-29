def maxprime(n):
    maxvalue = None
    if n <= 2:
        return maxvalue
    
    for i in range(2,n+1):
        for j in range(2,i+1):
            if i % j ==0:
                break
        if i == j :
            maxvalue = i
    return maxvalue

n = int(input())

print(maxprime(n))
