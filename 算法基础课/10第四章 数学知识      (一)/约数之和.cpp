#include<bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

//�𰸶�1e9+7ȡģ������˵��Ӧ�ñȽϴ���long long
typedef long long LL;

int main()
{
	
	int n;
	cin>>n;
	
	unordered_map<int,int> primes;
	
	while(n--)
	{
		int x;
		cin>>x;
		
		for(int i=2;i<=x/i;i++)
		{
			while(x%i==0)
			{
				x/=i;
				primes[i]++;
			}
		}
		if(x>1)primes[x]++;
	}
	
	
	LL res=1;
	for(auto prime :primes)
	{
		int p=prime.first;
		int a=prime.second;

		
		/*
		�Լ�д�� 
		LL t=0;
		for(int i=0;i<=a;i++)
		{
			int tmp=p;
			while(i>0)
			{
				tmp*=tmp;
				i--;
			}
			t+=tmp;
		}
		t++;//0�η�����1������ѡ�������� 
		res*=t;
		*/
		
		LL t=1;
		while(a--)t=(t*p+1)%mod;//�����Ҫmod��ֹ���
		res=res*t%mod;//����ҲҪmod��ֹ���
	}
	cout<<res<<endl;
	
	return 0;
}
