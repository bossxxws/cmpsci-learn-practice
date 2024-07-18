#include<bits/stdc++.h> 

using namespace std;

int n;

typedef long long LL;

const int N=1e5+3;

LL s[N];
LL t[N];
LL l,r,c;
bool check(LL k)//检查第k秒的星星数量是否超过c
{
    LL rs=0;
    for(int i=1;i<=n;i++)
    {
        if(k>=s[i])
        {
            rs+=(k-s[i])/t[i]+1;
            //cout<<rs<<endl;
		}
    }
    return rs>=c;
}

int main( )
{
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
	}
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
	}
    

    cin>>l>>r>>c;
    
    for(int i=1;i<=n;i++)
    {
        if(s[i]<l)
        {
            s[i]+=((l-s[i])/t[i])*t[i];
        }
        //cout<<s[i]<<endl;
        if(s[i]<l)s[i]+=t[i];
	}
    
	while(l<r)
	{
        LL mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
        //cout<<mid<<endl;
	}

    
    if(check(l))cout<<l;
    else cout<<-1;

    return 0;
}
