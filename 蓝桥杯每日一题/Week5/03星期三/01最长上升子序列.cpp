#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int a[N];

int f[N]; 


int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=a[i];
	}
	int res=-1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
		{
			//f[i]=max(f[i],f[j]);����ģ���Ȼj��iС��a[j]��һ����a[i]С
			if(a[i]>a[j])f[i]=max(f[i],f[j]+a[i]);
			//cout<<f[i]<<" ";
			res=max(res,f[i]);
		}
	cout<<res;
	return 0;
}
