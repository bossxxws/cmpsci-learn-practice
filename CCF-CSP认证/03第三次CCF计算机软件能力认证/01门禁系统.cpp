#include<bits/stdc++.h>

using namespace std;

int n;

const int N=1003;

int a[N];
int cnt[N];

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		cout<<cnt[a[i]]<<" ";
	}
	
	return 0;
}
