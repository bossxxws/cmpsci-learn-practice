//一万次询问 1<=b<=a<=1e5 预处理阶乘 

//cab=a！/（b！*（a-b）！）

//1e9+7是一个质数，故可以用费马小定理 

//时间复杂度： N*logN 
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N=1e5+10,mod=1e9+7;

int fact[N],infact[N];

int qmi(int a,int k,int p)
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

int main()
{
	fact[0]=infact[0]=1;
	for(int i=1;i<N;i++)
	{
		fact[i]=(LL)fact[i-1]*i%mod;
		infact[i]=(LL)infact[i-1]*qmi(i,mod-2,mod)%mod;//费马小定理求逆元 
	}
	
	int n;
	cin>>n;
	
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		cout<<(LL)fact[a]*infact[b]%mod*infact[a-b]%mod<<endl;
		//这里如果用除法会造成（f【a】 % mod）/（f【a-b】*f【b】 % mod ）
		//虽然解决了溢出问题，但是： 
		// 这与 （  f【a】 /（f【a-b】*f【b】）  ） % mod       并不等价 
		// 所以考虑转化为连乘的形式，求逆元然后转化为连乘的形式
		//f[a]*if[b]%mod*if[a-b]%mod
		//这样就可以使用mod来避免溢出的情况 
	}
	
	return 0;
} 
 
