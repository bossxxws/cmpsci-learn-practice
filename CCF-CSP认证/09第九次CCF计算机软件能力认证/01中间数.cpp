#include<bits/stdc++.h>

using namespace std;

int n; 
const int N=1003;

int a[N];
int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
//	int k=unique(a+1,a+1+n)-(a+1)+1;
//	cout<<k<<endl;
	int ans=-1;
	int k=n;
	if(n%2==0)
	{
		if(a[k/2]!=a[k/2+1])
		{
			cout<<ans;
			return 0;
		}
		else
		{
			int l=k/2;
			int r=k/2+1;
			while(l>=1 && a[l]==a[k/2])l--;
			while(r<=n && a[r]==a[k/2+1])r++;
			if(r-(k/2+1)!=(k/2)-l)cout<<ans;
			else cout<<a[k/2+1];
			return 0;
		}
	}
	else
	{
		int l=k/2+1;
		int r=k/2+1;
		while(l>=1 && a[l]==a[k/2+1])l--;
		while(r<=n && a[r]==a[k/2+1])r++;
		
//		cout<<l<<" "<<k/2+1<<" "<<r<<endl;
		if(r-(k/2+1)!=(k/2+1)-l)cout<<ans;
		else cout<<a[k/2+1];
		return 0;
	}
	
	
	
	
	return 0;
}
