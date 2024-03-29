//20    1<=b<=a<=1e18    1<=p<=1e5     卢卡斯定理    lucas

//C a b   *同余*   C (a mod p) (b mod p)    *    C (a/p) (b/p)  mod p


#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int p;

int qmi(int a,int k)
{
	int res=1;
	while(k)
	{
		if(k&1)res=(LL)res*a%p;
		a=(LL)a*a%p;
		k>>=1;
	}
	return res;
}

int C(int a,int b)
{
	int res=1;
	for(int i=1,j=a;i<=b;i++,j--)//最人类的写法 
	{
		res=(LL)res * j % p;
		res=(LL)res * qmi(i,p-2) %p;//求i的逆元
	}
	return res;
}

int lucas(LL a,LL b)
{
	if(a<p && b<p)return C(a,b);
	return (LL)C(a%p,b%p) * lucas(a/p,b/p) %p; 
}

int main()
{
	int n;
	cin>>n;
	
	while(n--)
	{
	    LL a,b;
		cin>>a>>b>>p;
		
		cout<<lucas(a,b)<<endl;
	}	
	return 0;
}
