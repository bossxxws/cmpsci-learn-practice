#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define x first
#define y second

const int N=100000+5;

LL res;

int gcd(int a,int b)
{
	return b?gcd(a%b,a):a;//�κ�����0����0��a��0�����Լ������a���� 
	//a=a%b
	//b=a
}

int a[N];
int n;
int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//cout<<a[i]<<endl;
	}
	
	sort(a+1,a+n+1);
	
	int d=0;//�����Լ������������d 
	
	
	//d=0��ʱ��res=n
	//d��=0��res=��ĩ��-���/d +1 
	for(int i=1;i<=n;i++)d=gcd(d,a[i]-a[1]); 
/*
for(int i=2;i<=n;i++)
{
	if(a[i]-a[i-1]!=d)
	{
		int l=(a[i]-a[i-1])/d-1;

		res+=l;
	}
}
*/	
	if(d==0)res=n; 
	else
	{
		res=(a[n]-a[1])/d+1;
	}
	cout<<res;
	return 0;
}

