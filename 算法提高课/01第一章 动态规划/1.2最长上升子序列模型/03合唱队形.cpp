#include<bits/stdc++.h>

using namespace std;

const int N=103;

int n;

int a[N]; 

int f[N];
int g[N]; 

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	//������Ҫ��λͬѧ���У���ɺϳ����Σ�
	//�ϳ�����Ҫ���ǰ���������������У��Ӻ���ǰ������������	
	
	//�Ǿ��Ǻ͵�ɽ��࣬������������½�-1�����Ǻϳ�������ĳ���
	//Ȼ����n��ȥ����Ҫ��Ľ��
	
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		{
			if(a[i]>a[j])f[i]=max(f[i],f[j]+1);
		}
	}
	
	for(int j=n;j>=0;j--)
	{
		g[j]=1;;
		for(int i=n;i>j;i--)
		{
			if(a[j]>a[i])g[j]=max(g[j],g[i]+1);	
		}
		
	}

	int res=0;
	
	for(int i=1;i<=n;i++)res=max(res,f[i]+g[i]-1);
	
	cout<<n-res;
	
	return 0;
}
