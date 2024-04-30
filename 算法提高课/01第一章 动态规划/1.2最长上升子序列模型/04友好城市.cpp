#include<bits/stdc++.h>

using namespace std;

const int N=5003;

int a[N];
int b[N];

int f[N];

typedef pair<int,int> PII;

#define x first
#define y second

PII node[N];

int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&node[i].x,&node[i].y);
	}
	
	//ÅÅÐò
	sort(node+1,node+n+1);
	
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		{
			
			if(node[i].y>node[j].y)f[i]=max(f[i],f[j]+1);
			
		}
		
	}
	
	int res=0;
	
	for(int i=1;i<=n;i++)res=max(f[i],res);
	
	cout<<res;
	
	return 0;
}
