#include<bits/stdc++.h>

using namespace std;
/*
����д�� 
ʱ�临�Ӷ�Ϊn 
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

//�Ż��汾  ʱ�临�Ӷ�O��sqrt��n���� 
bool is_prime(int n)
{
	if(n<2)return false;
	for(int i=2;i<=n/i;i++)//����i*i<=n����Ϊ�������� 
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
