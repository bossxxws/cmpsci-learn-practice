//ŷ��������a��n���ʣ���a��phi[N]�η� mod n ͬ�� 1
//����С����a��p-1�η� mod p ��1  �����a��p������p�������� 

//������ 

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
		if(k&1)res=res*a%p;//�����ǰk��ĩβ��1�������Ʊ�ʾ�� 
		k>>=1;//����ȥ�����һλ
		a=a*a%p;//��aƽ���Դ���a�仯Ϊ��һλ��Ӧ���� 
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
