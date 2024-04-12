#include<bits/stdc++.h>

using namespace std;

//100000000 £¨Ìî¿Õ£© 

typedef long long LL;

LL a,b;

LL quickmi(LL x,LL y)
{
	LL res=x;
	while(y)
	{
		if(y>>1&1)
		{
			res=res*x;
		}
		x=x*x;
		y/=2;
	}
	return res;
}

int main()
{
	scanf("%lld%lld",&a,&b);
	
	//cout<<a<<" "<<b<<endl;
	
	//cout<<quickmi(a,2)<<endl;
	//cout<<quickmi(b,2)<<endl;
	
	cout<<quickmi(a,2)-quickmi(b,2);
	
	return 0;
} 
