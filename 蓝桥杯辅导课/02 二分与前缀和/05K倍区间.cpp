//���� long long �����ڣ����� 
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

long long a[N];//ǰ׺������ᱬint 

int m[N];

int main()
{
	int n,k;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];//����ǰ׺�� 
	}
	m[0]=1;
	long long res=0;//res�ᱬint 
	for(int i=1;i<=n;i++)
	{
		if(m[a[i]%k])res+=m[a[i]%k];
		m[a[i]%k]++;
	}
	cout<<res;
	return 0;
}

