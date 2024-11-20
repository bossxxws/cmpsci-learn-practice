#include<bits/stdc++.h>

using namespace std;
int n;
const int N=1003;

int a[N];

int res;

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];		
	}	
		
	for(int i=1;i+1<=n;i++)
	{
		int t=abs(a[i]-a[i+1]);
		res=max(t,res);
	}
	
	cout<<res;
	return 0;
}
