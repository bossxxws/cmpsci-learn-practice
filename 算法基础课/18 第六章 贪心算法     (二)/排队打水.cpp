//让打水最快的先打
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

typedef long long LL;

int n;
int t[N];

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>t[i];
	
	sort(t,t+n);
	
	LL res=0;
	for(int i=0;i<n;i++)res+=t[i]*(n-i-1);
	
	cout<<res<<endl;
	
	return 0;
} 
