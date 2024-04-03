#include<bits/stdc++.h>

using namespace std;

const int N=52;

int n;
int X;

int a[N];

int main()
{
	cin>>n;
	
	cin>>X;
	
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int l=0,r=0;
	for(int i=1;i<n;i++)
	{
		
		if(abs(a[i])>abs(X) && a[i]<0)l++;
		
		if(abs(a[i])<abs(X) && a[i]>0)r++;
	
	}
	
	if((l ==0 && X>0) || r ==0 && X<0)cout<<1<<endl;
	else cout<<l+r+1<<endl;
	
	return 0;
}
