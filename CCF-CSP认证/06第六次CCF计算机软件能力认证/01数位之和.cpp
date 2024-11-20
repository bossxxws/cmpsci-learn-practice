#include<bits/stdc++.h>

using namespace std;

int n; 

int main()
{
	cin>>n;
	
	int cnt=0;
	while(n)
	{
		int t=n%10;
		cnt+=t;
		n/=10;
	}
	
	cout<<cnt<<endl;
	return 0;
}
