#include<bits/stdc++.h>

using namespace std;

const int N=12;
const int M=1<<11;

int n,m;

long long  f[N][M];//��i�е�״̬ΪM ��j��ʾ��ͷ�ķ������� 

bool st[M];//������ʾĳһ��״̬�Ƿ�Ϸ� 

int main()
{

	while(cin>>n>>m,n || m)
	{
		memset(f,0,sizeof f);
		
		//��ʼԤ����
		for(int i=0;i<1<<n;i++)//ö��ÿһ��״̬ 
		{
			int cnt=0;//��¼�����Ŀո����� 
			st[i]=true; 
			for(int j=0;j<n;j++)
			{
				if(i>>j&1)//���λ�ò��ǿո� 
				{
					if(cnt&1)st[i]=false;//���λ��֮ǰ�������ո����������������Ϸ� 
					cnt=0;
				}
				else cnt++;
			}
			if(cnt&1)st[i]=false; 
		}

		f[0][0]=1;//��0��û����һ�У�����û�д�������
		//С������ʲô��û�зţ�ֻ����һ��״̬ 
		
		for(int i=1;i<=m;i++)//ö���� 
		{
			for(int j=0;j<1<<n;j++)//ö����һ�е�״̬ 
			{
				for(int k=0;k<1<<n;k++)//ö����һ�е�״̬ 
				{
					if(((j&k)==0) && st[j|k])//(k�м���j�������ĸ��Ӻ�Ҫ�Ϸ�)
					{
						f[i][j]+=f[i-1][k];
					}
				}
			}
		} 
		cout<<f[m][0]<<endl;
	}
	

	return 0;
}
