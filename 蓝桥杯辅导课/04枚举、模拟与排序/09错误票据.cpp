#include<bits/stdc++.h>

using namespace std;

int n;

const int N=1e5+5;

int m[N];

int main()
{
	int maX=-1;
	int miN=100002;
	cin>>n;
	int a;
	while(n--)
	{
		while(cin>>a)
		{
			m[a]++;
			maX=max(maX,a);
			miN=min(miN,a);
		}
	}
	int p,q;
	for(int i=miN;i<=maX;i++)
	{
		if(m[i]==0)p=i;
		if(m[i]==2)q=i;
	}
	
	cout<<p<<" "<<q;
	
	return 0;
}
