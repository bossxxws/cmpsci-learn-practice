#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int n,k;

const int N=1e5+5;

int a[N];
LL s[N];

int m[N];

int main()
{
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	
	//��ʼ��������
	LL res=0;

    m[0]++;//��Ϊ%0��������0�������������s[i]%k==0��Ϊ�˷������⣬��ϣ��0��λ��Ҫ��ǰ����1

	for(int i=1;i<=n;i++)
	{
		res+=m[s[i]%k];
		m[s[i]%k]++;
	} 
	cout<<res<<endl;
	return 0;
} 
