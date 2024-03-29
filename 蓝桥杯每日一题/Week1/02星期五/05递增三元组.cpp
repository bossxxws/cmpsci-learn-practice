#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=1e5+5;

int n;

int a[N],b[N],c[N];
//求前缀和后就能知道记录前n大的数有几个 
int ma[N],mc[N];
int sa[N],sc[N];

int main()
{
	cin>>n;
	
	//读入A 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); 
		ma[a[i]]++;
	}
	
	sa[0]=ma[0];//0的个数也不能忽略
	
	//计算A组前缀和 
	//sa[i]存的是小于等于i的个数
	for(int i=1;i<N;i++)sa[i]=sa[i-1]+ma[i];
	
	
	//读入b
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	 
	//处理c 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		mc[c[i]]++;
	}
	
	sc[0]=mc[0];//0的个数也不能忽略
	
	//计算A组前缀和 
	//sc[i]存的是小于等于i的个数
	for(int i=1;i<N;i++)sc[i]=sc[i-1]+mc[i];
	
	//询问B
	LL res=0;
	for(int i=1;i<=n;i++)
	{
	    //cout<<sc[11];
		int t =b[i];
		//cout<<t<<endl;
		//cout<<sa[t-1];
		//cout<<sc[N-1]<<endl;
		res+=(LL)sa[t-1]*(sc[N-1]-sc[t]);
	}
	
	cout<<res;
	return 0;
} 
