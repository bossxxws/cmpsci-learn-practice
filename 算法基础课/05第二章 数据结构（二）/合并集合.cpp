//并查集 
/*
1.将两个元素合并
2.询问两个元素是否在一个集合中 
*/ 
//基本原理：用tree存储集合。树根的编号就是整个集合的编号
//         每个节点存储他的父节点，p[x]x的表示父节点 
//如何判断树根 if p【x】==x
//如何求x的集合编号 while（p【x】！=x）x=p【x】
//如何合并两个集合 px是x的集合编号，py是y的集合编号。p【x】=y 
//优化：
//找出根节点：第一次搜索之后直接标记根节点（路径压缩）
 
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;
int p[N]; 

int find(int x)  //返回x所在集合的编号 (祖宗节点) +路径压缩 
{
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)p[i]=i;
	while(m--)
	{
		char op[2];
		int a,b;
		cin>>op>>a>>b;
		if(op[0]=='M')p[find(a)]=find(b);//合并
		else 
		{
			if(find(a)==find(b))cout<<"Yes"<<endl;
			else cout<<"No"<<endl; 
		}
	}
	return 0;
}
