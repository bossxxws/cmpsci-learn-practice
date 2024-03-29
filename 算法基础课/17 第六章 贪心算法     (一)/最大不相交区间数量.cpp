#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

struct range
{
    int l,r;
    bool operator<(range w)
    {
        return r<w.r;
    }
}ra[N];

int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>ra[i].l>>ra[i].r;
    }
    
    int res=0;
    int ed=-2e9;
    
    sort(ra,ra+n);
    
    for(int i=0;i<n;i++)
    {
        if(ra[i].l>ed)
        {
            res++;
            ed=ra[i].r;
        }
    }
    cout<<res;
    return 0;
}
