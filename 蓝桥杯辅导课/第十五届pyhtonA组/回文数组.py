import os
import sys

import math

n = int(input())

data=list(map(int,input().split()))

n0=n//2

s=[]

for i in range(0,n0):
    s.append(data[i]-data[n-i-1])

'''
for i in range(len(s)):
    print(s[i],end=' ')
'''



ans=0

n1=len(s)

if(n==1):
    print(0)
else:
    f=False
    while(f==False):
        for i in range(0,len(s)):
            if(s[i]<0):
                if i+1<n1 and s[i+1]<0:
                    s[i]+=1
                    s[i+1]+=1
                    ans+=1
                    
                else:
                    s[i]+=1
                    ans+=1 #操作次数加一，此时只操作一个数
                    
            elif(s[i]>0):
                if i+1<n1 and s[i+1]>0:
                    s[i]-=1
                    s[i+1]-=1
                    ans+=1
                else:
                    s[i]-=1
                    ans+=1
        cnt=0
        for i in range(0,n1):
            if s[i]==0:
                cnt+=1;
        if(cnt==n1):
            f=True


    print(ans)
                      
        
