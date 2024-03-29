//用差分处理每个位置被询问的次数
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int n,m;

const int N=1e5+3;

int a[N],b[N];

int main()
{
    cin>>n;
    //cout<<n<<m<<endl;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
    	int l,r;
    	cin>>l>>r;
    	//cout<<l<<" "<<r<<endl;
    	b[l]++;
    	b[r+1]--;
    	
    	//区间两端，经过前缀和计算后就是 询问次数 
    }
    
    LL sum1=0,sum2=0;//sum1是原来的，sum是变大的 
    
    for(int i=1;i<=n;i++)//区间范围是小于等于n的，所以枚举到n即可（一开始想枚举到N） 
    {
        //cout<<b[i]<<endl;
    	b[i]=b[i]+b[i-1]; 
    	//cout<<b[i]<<endl;
    	sum1+=(LL)a[i]*b[i];
    }
    
    sort(a+1,a+n+1);sort(b+1,b+n+1);
    
    for(int i=1;i<=n;i++)
    {
    	sum2+=(LL)a[i]*b[i];
    }
    
    cout<<sum2-sum1;
    
    return 0;
}
