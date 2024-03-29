#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

#define x first
#define y second

const int N=105;

int a[N],b[N],s[N];

int main()
{
	int n,T;
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++)cin>>b[i];
	
	for(int i=2;i<=n;i++)cin>>s[i];
	
	cin>>T;

	for(int i=2;i<=n;i++)s[i]+=s[i-1];//求第一个鱼塘到第i个的时间
	//cout<<s[2];
	int res=0;
	for(int i=1;i<=n;i++)
	{
		int havetime=T-s[i];
		
		priority_queue<PII,vector<PII>> rivers;
		
		int fish=0;
		
		for(int k=1;k<=i;k++)
		{
			rivers.push({a[k],k});//鱼塘入堆，开始钓！ 
		}
		
		while(!rivers.empty() && havetime>0)
		{
			
			PII t=rivers.top();
			rivers.pop();
			fish+=t.x;
			havetime-=1;
			if(t.x-b[t.y]>0)rivers.push({t.x-b[t.y],t.y});
		}
		//cout<<fish<<endl;
		res=max(fish,res);
	} 
	
	cout<<res;
	return 0;
}
