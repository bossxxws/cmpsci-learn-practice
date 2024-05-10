#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

const int N=1e6+10;

int n,m;

int h[N],e[N],ne[N],idx;

int dist[N];
bool st[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main()
{
	memset(h,-1,sizeof h);
	
	add(0,1);
	
	add(0,3);
	
	add(1,2);
	
	add(2,0);
	
	add(2,5);
	
	add(2,6);
	
	add(3,1);
	
	add(4,3);
	
	add(4,0);
	
	add(4,5);
	
	add(5,6);
	
	add(6,5);
	
	for(int i=0;i<=6;i++)
	{
		cout<<i<<": ";
		for(int j=h[i];j!=-1;j=ne[j])
		{
			int d=e[j];
			cout<<d<<" ";
		}
		cout<<endl;
	}

	return 0;
}

