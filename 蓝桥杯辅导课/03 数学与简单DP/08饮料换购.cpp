#include<bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin>>n;
	
	int cnt=n;
	
	int t=0;
	
	while(n || t>=3)
	{
		int x=n/3;
		t+=t%3;
		n=x;
		cnt+=x;
		if(t>=3)
		{
			cnt+=t/3;
			t-=3*cnt;
		}
	}
	cout<<cnt;
	return 0;
}
