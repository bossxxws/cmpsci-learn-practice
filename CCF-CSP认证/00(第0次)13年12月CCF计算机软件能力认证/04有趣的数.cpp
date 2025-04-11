#include<bits/stdc++.h>

using namespace std;

const int mod=1e9+7,N=1010;
int n; 


typedef long long LL;
LL C[N][N];
int main()
{
	//假设01选k个： 
	//先选k个01填充（C n-1 k，这n-1是因为第一位不能是0或者1），其中01序列中的组合数量是（k-1） 种
	//剩下的23组合同理 有（n-k-1）  种类
	//相乘 
	
	//依次把每个k的取值都叠加（从2到n-2） 
	cin>>n;
	
	//预处理出所有组合数 
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!j)C[i][j]=1;
			else 
			{
				C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
			}
		}
	}
	LL res=0;
	for(int i=2;i<=n-2;i++)
	{
		res=(res+(LL)C[n-1][i]*(i-1)%mod*(n-i-1))%mod;
	}
	
	cout<<res;
	return 0;
} 
