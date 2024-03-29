//限制值完全背包的是背包空间
//限制多重背包的是物品数量
#include<bits/stdc++.h>

using namespace std;

const int N=25000;//1000 * log 2000(以2为底)

int n,m;
int f[N];
int v[N],w[N],s[N];


int main()
{
	cin>>n>>m;
	
	
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int vi,wi,si;
		cin>>vi>>wi>>si;
		//cout<<vi<<wi<<si;
		int k=1;
		while(k<=si)
		{
			cnt++;
			si-=k;
			v[cnt]=k*vi;
			w[cnt]=k*wi;
			//cout<<w[cnt];
			k=k*2;
		}
		if(si>0)
		{
			cnt++;
			v[cnt]=si*vi;
			w[cnt]=si*wi;
		}
	}
	
	int n=cnt;
	
	//01背包的模板
	for(int i=1;i<=n;i++)
		for(int j=m;j>=v[i];j--)
			f[j]=max(f[j],f[j-v[i]]+w[i]);
			
	cout<<f[m];	
	return 0;	
} 
