#include<bits/stdc++.h>

using namespace std;

int m,n;

const int N=14;

const int M=1<<N;//һ�������ô���״̬ 

const int K=N*N;

int g[N];

int f[N][M]; //f[i][k]��ʾ��i������״̬Ϊk 

//int cnt[M];//�洢ÿ��״̬��Ӧ���������� 

vector<int>state;
vector<int>head[M]; 

const int mod=1e8; 

bool check(int state)
{
	return !(state & state << 1);
}


int main()
{
	scanf("%d%d",&n,&m);
	
	//�������׵�
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int t;
			cin>>t;
			g[i]|=!t<<j;
		}
	}
	
	for(int st=0;st<1<<m;st++)
	{
		if(check(st))
		{
			state.push_back(st);//Ԥ����Ϸ�״̬ 
		}
	}
	
	for (auto st: state)
        for (auto ne_st: state)
            if (!(st & ne_st))
                head[st].push_back(ne_st);  //Ԥ����Ϸ�״̬�ĺϷ�ת��
	 
	f[0][0]=1;
	 
	for(int i=1;i<=n+1;i++)
	{
		for(auto st:state)
		{
			if(!(st & g[i]))
			{
				for(auto pre_st:head[st])
				{
					f[i][st]=(f[i][st]+f[i-1][pre_st])%mod;//ͨ����һ���״̬ת�� 
				}
			}
		}
	 } 
// 	cout<<f[n][0]<<endl;
	cout<<f[n+1][0]<<endl;
	return 0;
} 	
