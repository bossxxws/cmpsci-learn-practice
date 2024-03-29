#include<bits/stdc++.h>

using namespace std;

int n,D,k;

typedef pair<int,int> PII;

const int N=1e5;

int hh=0;
int hot[N];

int cnt[N],st[N];

PII pos[N];

int main()
{
	cin>>n>>D>>k;
	
	for(int i=1;i<=n;i++)
	{
		int t,d;
		scanf("%d%d",&t,&d);
		
		pos[i]={t,d};
	}
	
	//cout<<"yes"<<endl;
	sort(pos+1,pos+n+1);
	
	//D时间内 大于等于K 
	for(int i=1,j=0;i<=n;i++)
	{
        cnt[pos[i].second]++;
		
		while(j<=n && pos[i].first>=pos[j].first+D)
		{
			cnt[pos[j].second]--;
			//cout<<pos[j].second<<endl;
			j++;
		}
		
		if(cnt[pos[i].second]>=k)st[pos[i].second]++;
	}
	
	for(int i=0;i<=N;i++)if(st[i])cout<<i<<endl;
	
	return 0;
}
