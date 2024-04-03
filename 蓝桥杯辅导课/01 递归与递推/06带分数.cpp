#include<bits/stdc++.h>

using namespace std;

const int N=600;

int n;

int ans;

int had_use[N];

int toolmap[N];

bool check(int a,int c)
{
	int b=n*c-a*c;
	
	memcpy(toolmap,had_use,sizeof toolmap);
	
	if(!a || !b || !c)return false;//不能有0 
	
	while(b)
	{
		int t=b%10;

		if(!t || toolmap[t])return false;//!t代表带0，toolmap代表重复 
		
		toolmap[t]=1;
		b/=10;
	}
	
	for(int i=1;i<=9;i++)if(!toolmap[i])return false;
	
	return true;
}

void dfs_c(int x,int a,int c)//参数a用来配合c检查带分数是否合格 
{
	if(x>=10)return ;//超过九个数字，不合法，剪枝
	
	if(check(a,c))ans++;//检查目前的a、c是否合格 
	
	//枚举 c 
	for(int i=1;i<=9;i++)
	{
		if(!had_use[i])
		{
			had_use[i]=1;
			dfs_c(x,a,c*10+i);
			had_use[i]=0;
		}
	}
	 
}

void dfs_a(int x,int a)//x表示用的数的个数 
{
	if(a>=n)return ;//超过n的 a 没有意义 ，剪枝 
	
	if(x>=10)return ;//用的数字超过9个则不合法，剪枝 
	
	if(a)dfs_c(x,a,0);//选好a之后开始枚举c 
	
	for(int i=1;i<=9;i++)//a这个位置取某个数 
	{
		if(!had_use[i])
		{
			had_use[i]=1;//标记为用过 
			dfs_a(x+1,a*10+i);//进入递归 
			had_use[i]=0;//恢复现场 
		}
	}
}

int main()
{
	cin>>n;
	
	//n=a+b/c
	//cn=ac+b
	//b=cn-ac，这样可以求出b，只需枚举c 
	
	dfs_a(0,0);
	cout<<ans;
	return 0;
}
