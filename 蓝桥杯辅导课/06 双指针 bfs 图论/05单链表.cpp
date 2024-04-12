#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5; 

int head,e[N],ne[N],idx;

void init()
{
	head=-1;
	idx=0;
}

void add_to_head(int x)
{
	e[idx]=x;
	ne[idx]=head;
	head=idx++;
}

void add(int x,int k)
{
	e[idx]=x;
	ne[idx]=ne[k];
	ne[k]=idx++;	
}

void remove(int k)
{
	ne[k]=ne[ne[k]];
}

int main()
{
	init();
	int m;
	cin>>m;
	while(m--)
	{
		int k,x;
		char op;
		cin>>op;
		if(op=='H')
		{
			cin>>x;
			add_to_head(x);
		}
		else if(op=='D')
		{
			cin>>k;
			if(!k)head=ne[head];
			remove(k-1);
		}
		else
		{
			cin>>k>>x;
			add(x,k-1);//第k个插入的编号是k-1，（idx是从0开始的） 
		}

	}
	for(int i=head;i!=-1;i=ne[i])cout<<e[i]<<" "; 
	return 0;
}
