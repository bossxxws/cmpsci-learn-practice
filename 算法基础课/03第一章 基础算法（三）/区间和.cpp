#include<iostream>

using namespace std;

#include<vector>

#include<algorithm>

const int N=300010;

int a[N],s[N];

vector<int>alls;

vector<pair<int,int>>add,ask;

int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(alls[mid]>=x)r=mid;
        else l=mid+1;
    }
    return r+1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        ask.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    //处理插入
    for(auto ele:add)
    {
        int pos=find(ele.first);
        a[pos]+=ele.second;
    }
    //预处理前缀和
    for(int i=1;i<=alls.size();i++)s[i]=s[i-1]+a[i];
    for(auto ele:ask)
    {
        int l=find(ele.first),r=find(ele.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}

