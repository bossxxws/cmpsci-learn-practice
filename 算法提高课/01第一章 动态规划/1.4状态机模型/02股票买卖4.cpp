#include<bits/stdc++.h>

using namespace std;

const int N=1e5+3;

int n,k;

int a[N];

int f[N][103][2];

int main()
{
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}//�����Ʊ�ڵ�i��ļ۸�
	
	
	memset(f,-0x3f,sizeof f);
	
	for(int i=0;i<=n;i++)f[i][0][0]=0;//��0��ʼ��ʼ��
	
	//dp
	
	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<=k;j++)
	    {
	        //�ղ�״̬
	        f[i][j][0]=max(f[i-1][j][1]+a[i],f[i-1][j][0]);
	        //�ֲ�״̬
	        f[i][j][1]=max(f[i-1][j][1],f[i-1][j-1][0]-a[i]);//�����Ź���һ�������Ĺ�Ʊ���ף����Դ�j-1��ʼת��
	    }
	}
	int res=0;
	for(int i=1;i<=k;i++)res=max(res,f[n][i][0]);
	
	cout<<res;
	return 0;
}

