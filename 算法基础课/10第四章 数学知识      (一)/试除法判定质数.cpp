#include<bits/stdc++.h>

using namespace std;
/*
暴力写法 
时间复杂度为n 
bool is_prime(int n)
{
	if(n<2)return false;
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

*/

//优化版本  时间复杂度O（sqrt（n）） 
bool is_prime(int n)
{
	if(n<2)return false;
	for(int i=2;i<=n/i;i++)//不用i*i<=n是因为这可能溢出 
	{
		if(n%i==0)
			return false;
	}
	return true;
}


int main()
{
	int n;
	
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		if(is_prime(a))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
