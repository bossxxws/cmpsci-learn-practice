#include<bits/stdc++.h>
//需要快速完成两个操作 
//1、0~x中数的个数（优化：如果一个数出现过就是1，这样可以把求前缀的个数转化为求前缀和） 
//2、添加一个数x 

//根据特定的需求选择特定的数据结构

//本题选择树状数组（可以快速支持这两个操作）（线段树也可以） 
//树状数组能操作的线段树都能操作 
 
//树状数组的求解，下标要从1开始 
using namespace std;

const int N=15000+10; 

const int Max=32010;//坐标最大值 

int n;


int level[N],tree[Max];//答案、树状数组 

//树状数组的三个函数

int lowbit(int x)
{
	return x&-x;//返回的是x的二进制表示中最后一位1 
} 

int query(int x)
{
	//query表示查询1~x的总和
	int res=0;
	for(int i=x;i!=0;i-=lowbit(i))
	{
		res+=tree[i];
	}
	return res;
}

//add表示在某一个位置加上一个数
void add(int x,int v)
{
	for(int i=x;i<Max;i+=lowbit(i))
	{
		tree[i]+=v;
	}
 } 

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x++;//树状数组下标从1开始 
		int t=query(x);//统计一下1~x的数的总和 （也就是横坐标范围为1~x的星星的数量） 
		level[t]++;//这个等级的星星数++； 
		add(x,1);//把当前数加到树状数组当中 
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d\n",level[i]);
	 } 
	
	return 0;
} 
//树状数组能快速的求前缀和O(log n)
//能快速修改某一个数O（log n） 
