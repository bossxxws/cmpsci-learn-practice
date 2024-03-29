#include<bits/stdc++.h>

using namespace std;

const int N=1e5+3;

int a[N],b[N];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)scanf("%d",&a[i]);

    for(int i=1;i<=m;i++)
    {
        int l,r,c;
        cin>>l>>r>>c;
        b[l]+=c;
        b[r+1]-=c;
    }

    for(int i=1;i<=n;i++)
    {
        b[i]=b[i]+b[i-1];
        a[i]+=b[i];
        cout<<a[i]<<" ";
    }
}


