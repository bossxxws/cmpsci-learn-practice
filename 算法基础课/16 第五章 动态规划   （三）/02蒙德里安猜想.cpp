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
		
		//计算每种列的状态是否合法 
		for(int i=0;i<1<<n;i++)
		{
			st[i]=true;
			
			int cnt=0;
			
			for(int j=0;j<n;j++)
			{
				if(i>>j&1)
				{
					if(cnt&1)st[i]=false;//奇数个的话就标记为false; 
					cnt=0;
				}
				else cnt++;
			}
			
			if(cnt&1)st[i]=false;
		
		}
		
		f[0][0]=1;//第0列没有人戳出来，那一个状态：1 
		
		//枚举列
		for(int i=1;i<=m;i++) 
			for(int j=0;j<1<<n;j++)//枚举所有状态 
				for(int k=0;k<1<<n;k++)//枚举i-1列的所有状态 
				{
					if((j&k)==0 && st[j|k])
					//|是位或，||是逻辑或
					//&是位与，&&是逻辑与
					{
						f[i][j]+=f[i-1][k];//后面的[i-1][k]表示的是i-1的某种状态对应的方案数 
					}
				}
				
				
	cout<<f[m][0]<<endl;//最后一列是m-1列，所以如果合法，第m列就不能捅出来一个小方格，所以是j==0
	}

	 
	return 0;
}
