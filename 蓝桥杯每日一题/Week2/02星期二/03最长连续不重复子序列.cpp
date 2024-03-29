#include<bits/stdc++.h>

using namespace std;

int n;

const int N=1e5+5;

int a[N],m[N];

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int l=0,res=0;
	
	for(int r=0;r<n;r++)
	{
		while(m[a[r]] && l<=r)
		{
			m[a[l]]--;
			l++;
		}
		m[a[r]]++;
		res=max(r-l+1,res);
	}
	cout<<res;
	return 0;
} 
