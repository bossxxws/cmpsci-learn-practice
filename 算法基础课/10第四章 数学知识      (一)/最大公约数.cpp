#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	
	int n;
	cin>>n;
	
	while(n--)
	{
		int a;
		int b;
		cin>>a;
		cin>>b;
		int t=gcd(a,b);
		cout<<t;
		puts("");
	}
	
	return 0;
} 
