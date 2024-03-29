//每个技能都是一个等差数列

//暴力做法就是把每个等差数列排序，然后把这些元素全部放到一个数组中

//然后排序，取前M个就是能得到的最大的攻击力（这一点也用到了贪心的思想） 

#include<bits/stdc++.h>

typedef long long LL;

const int N=2e5+10;

int n,m; 

using namespace std;

int a[N],b[N];

int q[N];

int hh=0; 

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		while(a[i]>=b[i])
		{
			q[hh++]=a[i];
			a[i]-=b[i];
		}
		if(a[i]>0)q[hh++]=a[i];
	} 
	
	sort(q,q+hh,greater<int>());
	
	//至此排序完成
	//开始二分，如果比赛时这里可以直接暴力贪心前m个，拿分走人
	
	LL maxs=0;
	
	for(int i=0;i<m;i++)
	{
		maxs+=q[i];
	}
	
	cout<<maxs<<endl;
	
	return 0;
} 
