#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;
int h[N],e[N],ne[N],idx;
int d[N],q[N];

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}//邻接表头插法

int bfs()
{
	int hh=0,tt=0;
	q[0]=1;//队列里先添加一个编号1 
	memset(d,-1,sizeof d);
	d[1]=0;//编号为1与自己距离为0 
	while(hh<=tt)
	{
		int t=q[hh++];
		for(int i=h[t];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(d[j]==-1)
			{
				d[j]=d[t]+1;
				q[++tt]=j;
			}
		}
	}
	return d[n];
}

int main()
{
	cin>>n>>m;
	memset(h,-1,sizeof h);//-1表示邻接表为空（指向-1，即为空） 
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	
	cout<<bfs()<<endl;
	return 0;
}
