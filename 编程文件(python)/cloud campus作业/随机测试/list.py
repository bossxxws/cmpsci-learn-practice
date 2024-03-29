def rec(k):
    alphabetlist=["None","A","B","C","D","E","F","G","H","J","K"]
    if k==1:
        return "A"
    else :
        tem=rec(k-1)+alphabetlist[k]+rec(k-1)
    return tem
k=int(input())
print(rec(k))