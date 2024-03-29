//每个技能都是一个等差数列

//暴力做法就是把每个等差数列排序，然后把这些元素全部放到一个数组中

//然后排序，取前M个就是能得到的最大的攻击力（这一点也用到了贪心的思想） 

#include<bits/stdc++.h>

typedef long long LL;

const int N=2e5+10;

int n,m; 

using namespace std;

int a[N],b[N];

bool check(LL mid)
{
	LL res=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=mid)res+=(a[i]-mid)/b[i]+1;//加上第i项中大于等于mid的数的个数	
	}
	
	return res>=m;
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	} 
	
	
	int l=0,r=1e6;
	
	while(l<r)
	{
		LL mid=l+r+1>>1;
		if(check(mid))l=mid;//check（mid）表示检查大于等于mid的数是不是至少有m个
		//为什么是大于等于？因为mid也有可能是答案 
		else r=mid-1;
	}
	
	LL res=0,cnt=0;
	
	for(int i=0;i<n;i++)
	{
		if(a[i]>=r)
		{
			LL c=(a[i]-r)/b[i]+1;
			LL end=a[i]-(c-1)*b[i];
			cnt+=c;
			res+=(a[i]+end)*c/2;
		}	
	} 
	//cout<<r<<endl;
	//cout<<res<<endl;
	
	cout<<res-(cnt-m)*r<<endl;
	
	return 0;
} 
