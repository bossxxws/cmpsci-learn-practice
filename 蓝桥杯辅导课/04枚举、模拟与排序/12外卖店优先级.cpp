#include<bits/stdc++.h>

using namespace std;


const int N=1e4+5;

int n,m,t;

int a[N][N];
int st[N];

int pre[N];//��i�ҵ��̵����ȼ� 

int main()
{
	cin>>n>>m>>t;
	//m������
	//���̱��1~n
	//tʱ���� 
	while(m--)
	{
		int ts,id;//tsʱ��id�յ�һ������ 
		scanf("%d%d",&ts,&id);
		
		a[ts][id]+=1;//ĳһʱ�̵Ķ������� 
	}
	
	
	//ö��ÿһ��ʱ���
	for(int i=1;i<=t;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]>0)pre[j]+=a[i][j]*2;
			else
			{
				pre[j]-=1;
				if(pre[j]<0)pre[j]=0;
			}
			if(pre[j]>5)st[j]=1;
			if(pre[j]<=3)st[j]=0;	
		} 
	int res=0;
	for(int i=1;i<=n;i++)res+=st[i];
	cout<<res;
	return 0;
}
