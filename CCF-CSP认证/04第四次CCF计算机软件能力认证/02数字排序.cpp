#include<bits/stdc++.h>

using namespace std;

int n; 

const int N=1003;

struct datax
{
	int v;
	int cnt;
}a[N];

int g[N];
int ct[N];

int aux[N];

bool cmp(datax a,datax b)
{
	if(a.cnt==b.cnt)return a.v<b.v;
	return a.cnt>b.cnt;
}

unordered_map<int,int>m;

int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&g[i]);
		m[g[i]]++;
	}
	
	int k=0;
	for(auto t:m)
	{
//		cout<<t.first<<" "<<t.second<<endl;
		a[++k].v=t.first;
		a[k].cnt=t.second;
	}
	
	sort(a+1,a+k+1,cmp);
	
	for(int i=1;i<=k;i++)
	{
		cout<<a[i].v<<" "<<a[i].cnt<<endl;
	}
	
	return 0;
}
