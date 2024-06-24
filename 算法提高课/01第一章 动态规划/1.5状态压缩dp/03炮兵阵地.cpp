#include<bits/stdc++.h>

using namespace std; 

const int N=13,M=1<<N;

int g[130];

int n,m; 

int f[2][M][M];//滚动数组，行数那一列开为2就行了
//滚动数组原理：
//因为行数是奇偶交换的，并且状态转移只依赖于上一行的状态
//所以说&1就可以区分本行和上一行，然后取最大值，所以说用滚动数组是可行的 

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

//计算出这一行有多少个炮兵
int count(int state)
{
	int res=0;
//	cout<<1<<endl;
	while(state)
	{
		if(state&1)res++;
		state=state>>1;
	}
	return res;
} 

int main()
{

	cin>>n>>m;
	 
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
//	cout<<"--"<<endl; 
	//预处理合法转移状态同时进行dp 
	for(int i=1;i<=n+2;i++)
	{
		//枚举三行的状态 
		for(int j=0;j<legal.size();j++)
		{
			for(int k=0;k<legal.size();k++)
			{
				for(int u=0;u<legal.size();u++)
				{
					int a=legal[j];//当前行 i 
					int b=legal[k];//上一行 i-1 
					int c=legal[u];//上上行 i-2
					if(a & b || a&c || b&c)continue;//三行都不能出现有炮兵在一列
					//出现就不是合法形式，直接continue下一个 
					
					//炮兵不能放在山坡上
					//i-2的情况也要算上
					//加一个特判就行了 
					if(i>=2)if(g[i]&a|| g[i-1] &b || g[i-2]&c) continue;
					else
					{
						if(g[i]&a || g[i-1]&b)continue;
					}
					
					//如果合法就进行状态转移
					
					//dp 
					//不取当前状态 和 取当前状态 中取最大值 
					//取当前状态的情况下：
					//上一行的最大值加上当前行的数量
					//然后和其他状态下最大的f（不取当前行的状态）取max 
					f[i&1][j][k]=max(f[i&1][j][k],f[i-1 &1][k][u]+cnt[a]);
					
				}
			}	
		}	
	} 
//	cout<<"--"<<endl; 
	cout<<f[n+2&1][0][0]<<endl;
	
	return 0;
} 
