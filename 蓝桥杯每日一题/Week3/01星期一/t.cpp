#include<bits/stdc++.h>

using namespace std;

int r;

int sum(int a,int n)
{
	int s=0;
	int k=0;
	for(int i=0;i<n;i++)
	{
		s=s*10+a;
		k+=s;
	}
	return k;
} 

int main()
{
	cin>>r;
	for(int i=0;i<r;i++)
	{
		int a,n;
		cin>>a>>n;
		int s=sum(a,n);
		
		cout<<s<<endl;
		
	}
	return 0;
}
