#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

typedef long long LL;

const int M=1e5;

int a[N];

int n; 
/*
30
29 2 24 14 9 17 29 22 11 13 15 30 27 19 15 30 7 24 6 4 17 18 12 24 25 11 23 27 30 27

20


*/
bool check(LL E)
{
	for(int i=0;i<n;i++)
	{
	    if(E>1e5)return true;
		if(a[i]>E)
		{
			E-=(LL)a[i]-E;
			if(E<0)return false;
		}
		else
		{
			E+=(LL)E-a[i];
			if(E<0)return false;
		}
	}
	return true;
}

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	int l=0,r=M;
	
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	//cout<<check(20)<<"yes?"<<endl; yes
	//cout<<check(34);
	printf("%d",r);
	return 0;
} 	
