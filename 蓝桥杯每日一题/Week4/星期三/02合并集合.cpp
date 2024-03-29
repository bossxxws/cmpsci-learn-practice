#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int n,m;


int p[N];

int find(int x)
{
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}

void merge(int a,int b)
{
	p[find(a)]=find(b);//a的祖先添加到b的祖先下面 
}

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)p[i]=i;
	
	
	
	while(m--)
	{
		char op;
		int a,b;
		cin>>op;
		cin>>a>>b;
		if(op=='M')
		{
			merge(a,b);
		}
		else
		{
			if(find(a)==find(b))cout<<"Yes"<<endl;
			else cout<<"No"<<endl; 
		}
	}
	//Yes No
	return 0;
} 
