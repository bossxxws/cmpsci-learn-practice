#include<bits/stdc++.h>

using namespace std;

int isleap(int t)
{
	if(t%100 && t%4==0 || t%400==0)return 1;
	else return 0;
} 

const int N=1e5;
int a[N],hh=0;

int main()
{
	int n,m;
	cin>>n>>m;
	
	
	for(int i=n;i<=m;i++)
	{
		if(isleap(i))a[hh++]=i;
	}
	
	int cnt=0;
	//cout<<isleap(2020);
	for(int i=0;i<hh;i++)
	{
		cnt++;
		cout<<a[i]<<" ";
		if(cnt%4==0)cout<<endl;
	}
	return 0;
}
