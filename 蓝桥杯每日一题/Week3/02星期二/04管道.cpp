#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10; 

typedef long long LL;

typedef pair<int,int> PII;

PII w[N],q[N];

int n,len;

bool check(int mid)//判断某一个时刻是否能注满 
{
	int cnt=0;//打开阀门的数量 
	for(int i=0;i<n;i++)
	{ 
		int pos=w[i].first;
		if(mid<w[i].second)
		{
			continue;//比该阀门打开时间晚，那就不计入
		}
		else
		{
			int d=mid-w[i].second;//经过的距离
			q[cnt].first=max(1,pos-d);
			q[cnt].second=min((LL)pos+d,(LL)len); 
			cnt++;
		}
	}
	//区间合并
	sort(q,q+cnt);
	
	int st=-2e9,ed=-2e9;
	
	for(int i=0;i<cnt;i++)
	{
		if(ed+1<q[i].first)//不能合并的情况 
		{
			st=q[i].first;
			ed=q[i].second;		
		}
		else ed=max(ed,q[i].second);	
	}
	//cout<<cnt<<endl;
	return st==1 && ed==len;
}

int main()
{
	cin>>n>>len;
	
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		w[i]={a,b};
	}
	
	int l=1,r=2e9;//最晚会在2e9覆盖 
	
	while(l<r)
	{
		int mid=(LL)l+r>>1;//用l=mid+1的模板
		if(check(mid))r=mid;
		else l=mid+1; 
	}
	
	cout<<l<<endl;
	
	return 0;
}
