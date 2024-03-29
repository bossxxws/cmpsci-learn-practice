#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

const int MOD=99999997;

typedef long long LL;

int n;
int a[N],b[N],c[N],tmp[N];

int p[N]; //离散化后的结果存在p数组内 

//要一一对应，就能让距离最小 

//离散化 
void work(int a[])
{
	for(int i=1;i<=n;i++)p[i]=i; 
	
	sort(p+1,p+n+1,[&](int x,int y)
	{
		{
			return a[x]<a[y];
		}
	});
	
	for(int i=1;i<=n;i++)a[p[i]]=i;//a中第i小的数的值为i，索引为p【i】，在a中赋值为i表示第i小的在a中第几个 
}

int merge(int l,int r)
{
	if(r<=l)return 0;
	int mid=(l+r)>>1;
	int k=0,i=l,j=r,res=0;
	while(i<=mid && j<=r)
	{
		if(b[j]>=b[i])tmp[k++]=b[i++];
		else
		{
			res+=mid-i+1;
			tmp[k++]=b[j++];
		}
	}
	while(i<=mid)
	{
		tmp[k++]=b[i++];
	}
	while(j<=r)
	{
		tmp[k++]=b[j++];
	}
	for(int i=l,j=0;i<=n;i++,j++)
	{
		b[i++]=tmp[j++];
	}
} 

int main()
{
	cin>>n;
    
    for(int i=1;i<=n;i++)cin>>a[i];
    
    for(int i=1;i<=n;i++)cin>>b[i];
    
    LL res=0;
    
    //让位置一一对应即可
	
	work(a);work(b);
	//work离散化之后，a和b都是挨着排序的，并且序号都是1-n 
	//并且是按照原来数组中从大到小的索引排列的
	//比如最低的火柴的索引是3，那么3就在最前面 
	
	for(int i=1;i<=n;i++)c[a[i]]=i; //把第三个位置的映射统一变成1 
	 
	
	for(int i=1;i<=n;i++)b[i]=c[b[i]];//把b按照映射重组一下 
    
    res=merge(0,n-1);
    
    cout<<res;
    
    return 0;
}
