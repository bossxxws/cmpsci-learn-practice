import os
import sys
import math

n = int(input())
data=list(map(int,input().split()))

f=False

s=[]
for i in range(0,n//2):
    s.append(int((data[i]-data[n-i-1])))
    #print(s[i])

n0=len(s)


ans=0

if(n==1):
    print(0)
else:
    while(f==False):
        for i in range(0,n0):
            if(s[i]<0):
                if(i+1<n0):
                    if(s[i+1]<0):
                        k=min(abs(s[i]),abs(s[i+1]))
                        #print(k)
                        s[i+1]+=k
                        s[i]+=k
                        ans+=k
                        #print(s[i])
                    else:
                        k=abs(s[i])
                        
                        
                        s[i]+=k
                        #print(s[i])
                        ans+=k
                else:
                    k=abs(s[i])
                        
                        
                    s[i]+=k
                    #print(s[i])
                    ans+=k
                
            elif s[i]>0:
                if(i+1<n0):
                    if(s[i+1]>0):
                        k=min(abs(s[i]),abs(s[i+1]))
                        s[i]-=k
                        s[i+1]-=k
                        ans+=k
                    else:
                        k=abs(s[i])
                        s[i]-=k
                        ans+=k
                else:
                    k=abs(s[i])
                    s[i]-=k
                    ans+=k
        cnt=0
        for i in range(0,n0):
            #print(s[i])    
            if(s[i]==0):
                cnt+=1
            else:
                break
        #print(cnt)
        if(cnt==n0):
            f=True
    print(ans)
            
                

    
