#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;

int p[N];
int cnt[N];

int find(int x)
{
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}

void merge(int a,int b)
{
	cnt[find(b)]+=cnt[find(a)];
	p[find(a)]=find(b);
}

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		cnt[i]=1;
	}
	
	while(m--)
	{
		char op[5];
		cin>>op;
		if(op[0]=='C')
		{
			int a,b;
			cin>>a>>b;
			if(find(a)==find(b))continue;
			merge(a,b);
		}
		else if(op[1]=='1')
		{
			int a,b;
			cin>>a>>b;
			if(find(a)==find(b))cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else
		{
			int t;
			cin>>t;
			cout<<cnt[find(t)]<<endl;
		}
	}
	
	
	return 0;
}
