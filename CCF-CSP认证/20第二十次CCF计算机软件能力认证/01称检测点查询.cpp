#include<bits/stdc++.h>

using namespace std;

int n,X,Y; 

typedef pair<int,int> PDI;

const int N=203;

PDI d[N];

bool cmp(PDI a,PDI b)
{
	if(a.first==b.first)
	{
		return a.second<b.second;
	}
	return a.first<b.first;
}

int main()
{
	cin>>n>>X>>Y;
	
	for(int i=1;i<=n;i++)
	{
		double x,y;
		cin>>x>>y;
		d[i].first=pow(X-x,2)+pow(Y-y,2);
		d[i].second=i;
	}
	
	sort(d+1,d+n+1,cmp);
	
	for(int i=1;i<=3;i++)cout<<d[i].second<<endl;
	return 0;
}
