#include<bits/stdc++.h>

using namespace std;


//�𰸶�1e9+7ȡģ������˵��Ӧ�ñȽϴ���long long
typedef long long LL;

const int mod=1e9+7;


int main()
{
	int n;
	cin>>n;
	
	unordered_map<int,int> primes;//�洢������ָ�� 
	
	while(n--)
	{
		//�ֽ�ÿ���������������ʽ 
		int x;
		cin>>x;
		
		//�ֽ���� 
		for(int i=2;i<=x/i;i++)
		{
			while(x%i==0)
			{
				x/=i;
				primes[i]++;//i����������ָ��+1 
			}
		}
		
		if(x>1)primes[x]++;//���x���껹�о�˵��x�����ǱȽϴ�ģ�Ҳ����˵����ģ������������� 5
		
	}	
	
	LL res=1;
	
	for(auto prime:primes)
	{
		res=res*(prime.second+1)%mod;//prime.second+1����Ϊn�η���ʵ��n+1��ѡ�񣨰�0�η����ϣ� 
	}
	
	cout<<res<<endl;
	
	return 0;
}
