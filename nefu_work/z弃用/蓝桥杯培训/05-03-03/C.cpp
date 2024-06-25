#include<bits/stdc++.h>

using namespace std;

int n;

const int N=1e5;

typedef pair<int,int> PII;
int vis[1000][1000];

PII pos[N]; 

int main()
{
	cin>>n;
	
	int res=0;
	
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		pos[i]={x,y};
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{

			if((abs(pos[i].first-pos[j].first)+abs(pos[i].second-pos[j].second))==1)
			{
				res++;
			}
		}
	}
	
	cout<<res<<endl;
	
	return 0;
}
