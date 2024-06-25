def dtob(n):
    if n==0:
        return '0'
    else :
        return dtobhel(n)
    


    



def dtobhel(n):
    if n==0:
        return "0"
    elif n>=2:
        tm=dtobhel(n//2)+str(n%2)
        return tm
    else:
        return '1'
print(dtobhel(15))