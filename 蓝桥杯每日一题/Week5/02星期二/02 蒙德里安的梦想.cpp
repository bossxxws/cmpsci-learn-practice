#include<bits/stdc++.h>

using namespace std;

const int N=12;
const int M=1<<11;

int n,m;

long long  f[N][M];//第i列的状态为M ，j表示出头的方格数量 

bool st[M];//用来表示某一种状态是否合法 

int main()
{

	while(cin>>n>>m,n || m)
	{
		memset(f,0,sizeof f);
		
		//开始预处理
		for(int i=0;i<1<<n;i++)//枚举每一种状态 
		{
			int cnt=0;//记录连续的空格数量 
			st[i]=true; 
			for(int j=0;j<n;j++)
			{
				if(i>>j&1)//这个位置不是空格 
				{
					if(cnt&1)st[i]=false;//这个位置之前的连续空格数量是奇数，不合法 
					cnt=0;
				}
				else cnt++;
			}
			if(cnt&1)st[i]=false; 
		}

		f[0][0]=1;//第0列没有上一列，所以没有戳出来的
		//小方块里什么都没有放，只有这一种状态 
		
		for(int i=1;i<=m;i++)//枚举列 
		{
			for(int j=0;j<1<<n;j++)//枚举这一列的状态 
			{
				for(int k=0;k<1<<n;k++)//枚举上一列的状态 
				{
					if(((j&k)==0) && st[j|k])//(k列加上j列向后伸的格子后要合法)
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
