#include<bits/stdc++.h>

using namespace std;

const int N=12,M=1<<N;

int n,m;

long long  f[N][M];

bool st[M];

int main()
{
	
	while(cin>>n>>m , n||m)
	{
		memset(f,0,sizeof f);
		
		//����ÿ���е�״̬�Ƿ�Ϸ� 
		for(int i=0;i<1<<n;i++)
		{
			st[i]=true;
			
			int cnt=0;
			
			for(int j=0;j<n;j++)
			{
				if(i>>j&1)
				{
					if(cnt&1)st[i]=false;//�������Ļ��ͱ��Ϊfalse; 
					cnt=0;
				}
				else cnt++;
			}
			
			if(cnt&1)st[i]=false;
		
		}
		
		f[0][0]=1;//��0��û���˴���������һ��״̬��1 
		
		//ö����
		for(int i=1;i<=m;i++) 
			for(int j=0;j<1<<n;j++)//ö������״̬ 
				for(int k=0;k<1<<n;k++)//ö��i-1�е�����״̬ 
				{
					if((j&k)==0 && st[j|k])
					//|��λ��||���߼���
					//&��λ�룬&&���߼���
					{
						f[i][j]+=f[i-1][k];//�����[i-1][k]��ʾ����i-1��ĳ��״̬��Ӧ�ķ����� 
					}
				}
				
				
	cout<<f[m][0]<<endl;//���һ����m-1�У���������Ϸ�����m�оͲ���ͱ����һ��С����������j==0
	}

	 
	return 0;
}
