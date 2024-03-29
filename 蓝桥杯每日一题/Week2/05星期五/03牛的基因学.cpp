#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=1e5+5,MOD=1e9+7;

int n,cnt[100];
char str[N];

int main()
{
	scanf("%d%s",&n,str);
	
	int mx=0,ct=0;
	for(int i=0;i<n;i++)
	{
		int t=++cnt[str[i]];
		//cout<<t;
		if(t>mx)mx=t,ct=1;
		else if(t==mx)ct++;
	}
	
	LL res=1;
	for(int i=0;i<n;i++)
		res=(LL)res*ct%MOD;
	cout<<res;
	return 0;
} 
