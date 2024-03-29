//每次最小的两个果子合并 
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    while(n--)
    {
        int x;
        cin>>x;
        minheap.push(x);
    }
    int res=0;
    while(minheap.size()>1)
    {
        int a=minheap.top();minheap.pop();
        int b=minheap.top();minheap.pop();
        res+=a+b;
        minheap.push(a+b);
    }
    cout<<res;
}
