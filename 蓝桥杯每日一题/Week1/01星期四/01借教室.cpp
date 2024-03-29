//想到一个区间想加减就该想到差分
//如果总有一天会迎来订单错误，那么这一天后的所有订单都会错误
//所以可以分为两段
//所以差分处理完数据后采用二分搜索 

#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n,m;//天数和订单数量
int rooms[N]; //每天可借教室的数量
//存储询问 
int d[N],s[N],t[N];
//差分数组
long long  b[N]; 

bool check(int mid)
{
	memset(b,0,sizeof b);
	
	//处理差分数组 
	for(int i=1;i<=mid;i++)
	{
		b[s[i]]  +=d[i];
		b[t[i]+1]-=d[i];//相当于 1到m个订单 ，每个订单的区间都减去 d【i】（当天要借的教室数） 
	}
	
	//求前缀和
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i]+b[i-1];
		//cout<<b[i]<<endl;
		if(b[i]>rooms[i])return false;//如果某一天借的大于当天的教室数量返回false 
	} 
	//cout<<"yes"<<endl;
	return true;
	
}

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&rooms[i]);
	}
	
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&d[i],&s[i],&t[i]);
	}
	
	int l=0,r=m;
	
	while(l<r)
	{
		int mid=r+l+1>>1;           //为什么要+1？  因为边界问题，+1非常重要 
		//cout<<mid<<endl;
		if(check(mid))l=mid;//正确，那就继续往后借教室 
		else r=mid-1;//check返回fasle就是表示订单错误，需要查看前面的是否也错误 
	}
	
	//如果没有错误，二分应该定格在r==m上，因为直到最后一天都没有错误
	if(r==m)cout<<0<<endl;
	//如果错误，则r==l==mid-1，定格在最早的错误的一天的前一天 
	else cout<<-1<<endl<<r+1<<endl; 
	
	return 0;
} 
