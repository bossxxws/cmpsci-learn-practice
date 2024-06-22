#include<bits/stdc++.h>

using namespace std; 

const int N=13,M=1<<N;

int g[130];

int n,m; 

int f[2][M][M];

vector<int>legal;
//vector<int>trans[M];

int cnt[M];

bool check(int state)
{
	for(int i=0;i<m;i++)
	{
		if(state>>i&1 && (state >> i+1 &1 || state >>i+2 &1))return false;//处理这一行的合法状态 
	}
	return true;
}

int count(int state)
{
	int res=0;
	while(state)
	{
		if(state&1)res++;
		state=state>>1;
	}
	return res;
} 

int main()
{
	int n,m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)//因为二进制表示要从第0位开始，所以j只能从0开始 
		{
			char k;
			cin>>k;
			if(k=='H')g[i]+=1<<j;//若为H则相当于山坡，不能放炮兵 
		}
	}
	
	//预处理合法状态
	for(int i=0;i< 1<<m;i++)
	{
		if(check(i))
		{
			legal.push_back(i);
			cnt[i]=count(i);
		}
	} 
	
	//预处理合法转移状态同时进行dp 
	for(int i=1;i<=n+2;i++)
	{
		//枚举三行的状态 
		for(int j=0;j<legal.size();i++)
		{
			for(int k=0;k<legal.size();k++)
			{
				for(int u=0;u<legal.size();u++)
				{
					int a=legal[j];//当前行 
					int b=legal[k];//上一行 
					int c=legal[u];//上上行 
					if(a & b || a&c || b&c)continue;//三行都不能出现有炮兵在一列
					//出现就不是合法形式，直接continue下一个 
					
					//炮兵不能放在山坡上
					if(g[i-1] &a || g[i]&b) continue;
					
					//如果合法就进行状态转移
					
					f[i&1][j][k]=max(f[i&1][j][k],f[i-1 &1][u][j]+cnt[b]);
					
				}
			}	
		}	
	} 
	
	cout<<f[n+2&1][0][0]<<endl;
	
	return 0;
} 
