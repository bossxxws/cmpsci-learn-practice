#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int a[N];

typedef long long LL;

int n;

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);//�����Ʊ��i��ļ۸� 
	
	//�����ڶ����Ǽ۾��򣬰���׬�Ķ�׬��
	
	LL res=0;
	
	for(int i=1;i<=n;i++)
	{
		if(i+1<=n)
		{
			int j=i+1;
			if(a[j]>a[i])
			{
				res+=(LL)a[j]-a[i];
			}
		}
		
	}
	cout<<res;
	return 0;
}
