//总和排序，最大的一定最小 

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

const int N=5e4+10;

int n;
PII cow[N];

int main()
{
    
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int w,s;
        cin>>w>>s;
        cow[i]={w+s,w};
    }
    
    sort(cow,cow+n);
    
    int res=-2e9,sum=0;
    
    for(int i=0;i<n;i++)
    {
        int w=cow[i].second,s=cow[i].first-w;
        res=max(res,sum-s);
        sum+=w;
    }
    
    cout<<res;
    
    return 0;
}
