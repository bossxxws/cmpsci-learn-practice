import math

def check(n):
    while n%2==0:
        n=n//2
    if(n==1):
        return True
    else:
        return False

n=int(input())
data=list(map(int,input().split()))

ans=0

for i in range(n):
    if(check(data[i])):
        ans+=1
print(ans)
    
        
