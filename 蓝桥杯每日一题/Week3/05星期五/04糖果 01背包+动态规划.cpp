/*
1、迭代加深
2、找选择最少的列
3、可行性剪枝（写一个估价函数h（）（最少要选多少行））


优化：
位运算来优化（状态压缩）

lowbit操作返回x的最后一位1
枚举的时候可以通过某个办法只枚举没有被选的列

11010

这种情况我们只枚举那两个0，而不再枚举1的情况 
*/
#include<bits/stdc++.h>

using namespace std;

const int N=110,M=1<<20,INF=0x3f3f3f3f;

int n,m,k;

vector<int>col[N];//哪些行能包含这一列

int log2[N];//求log以2为底N的对数 

int cnt[N];//每一列有多少选择 

int main()
{
	cin>>n>>m>>k;
	
	for(int i=0;i<m;i++)log2[1<<i]=i;//口味编号1~m 
	
	for(int i=0;i<n;i++)//读入每包糖果的数据 
	{
		int state=0;
		 
	}
	 
	return 0;
}
