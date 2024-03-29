//欧拉定理：若a与n互质，则a的phi[N]次方 mod n 同余 1
//费马小定理：a的p-1次方 mod p 余1  （如果a和p互质且p是质数） 

//快速幂 

#include<bits/stdc++.h> 

using namespace std;

typedef long long LL;

const LL N=2*1e9+10;


//a^k%p
LL qmi(LL a,int k,int p)
{
	LL res=1;
	while(k)
	{
		if(k&1)res=res*a%p;//如果当前k的末尾是1（二进制表示） 
		k>>=1;//右移去掉最后一位
		a=a*a%p;//把a平方以此让a变化为下一位对应的数 
	}
	return res;
}

int main()
{
	int n;
	cin>>n;
	
	while(n--)
	{
		int a,k,p;
		cin>>a>>k>>p;
		
		cout<<qmi(a,k,p)<<endl;
				
	}
	
	return 0;
}
