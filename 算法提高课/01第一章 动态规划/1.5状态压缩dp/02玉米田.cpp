#include<bits/stdc++.h>

using namespace std;

int m,n;

const int N=14;

const int M=1<<N;//一行最多这么多个状态 

const int K=N*N;

int g[N];

int f[N][M]; //f[i][k]表示第i行玉米状态为k 

//int cnt[M];//存储每个状态对应的玉米数量 

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
	
	//读入玉米地
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
			state.push_back(st);//预处理合法状态 
		}
	}
	
	for (auto st: state)
        for (auto ne_st: state)
            if (!(st & ne_st))
                head[st].push_back(ne_st);  //预处理合法状态的合法转移
	 
	f[0][0]=1;
	 
	for(int i=1;i<=n+1;i++)
	{
		for(auto st:state)
		{
			if(!(st & g[i]))
			{
				for(auto pre_st:head[st])
				{
					f[i][st]=(f[i][st]+f[i-1][pre_st])%mod;//通过上一层的状态转移 
				}
			}
		}
	 } 
// 	cout<<f[n][0]<<endl;
	cout<<f[n+1][0]<<endl;
	return 0;
} 	
