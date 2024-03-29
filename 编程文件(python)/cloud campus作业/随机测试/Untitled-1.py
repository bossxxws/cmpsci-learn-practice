def power(n,k):
    if k==1:
        return n
    if k %2==0:
        r= (n**(k/2))**2
    else:
        r= n*(n**(((k-1)/2))**2)
    return r
print(power(2,2))
        