//һ���ѯ�� 1<=b<=a<=1e5 Ԥ����׳� 

//cab=a��/��b��*��a-b������

//1e9+7��һ���������ʿ����÷���С���� 

//ʱ�临�Ӷȣ� N*logN 
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
		infact[i]=(LL)infact[i-1]*qmi(i,mod-2,mod)%mod;//����С��������Ԫ 
	}
	
	int n;
	cin>>n;
	
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		cout<<(LL)fact[a]*infact[b]%mod*infact[a-b]%mod<<endl;
		//��������ó�������ɣ�f��a�� % mod��/��f��a-b��*f��b�� % mod ��
		//��Ȼ�����������⣬���ǣ� 
		// ���� ��  f��a�� /��f��a-b��*f��b����  �� % mod       �����ȼ� 
		// ���Կ���ת��Ϊ���˵���ʽ������ԪȻ��ת��Ϊ���˵���ʽ
		//f[a]*if[b]%mod*if[a-b]%mod
		//�����Ϳ���ʹ��mod�������������� 
	}
	
	return 0;
} 
 
