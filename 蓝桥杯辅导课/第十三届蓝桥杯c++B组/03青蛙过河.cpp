#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N  = 1e5+10;
typedef long long LL;
LL s[N];
int n,x;
bool check(int m)
{
    for(int i =1;i+m<=n;i++)
        if(s[i+m-1]-s[i-1]<x)   return false;
    return true;
}
int main()
{
    cin>>n>>x;
    for(int i=1;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        s[i]=s[i-1]+a;
    }
    x*=2;
    int l=1,r=n;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid))  r=mid;
        else    l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}

