#include<bits/stdc++.h>

using namespace std;

const int N=600;

//typedef long long LL;

int ever[N],had_use[N];
//数组放在最上面，acwing平台由于放在了ans下面导致输出结果错误 

int ans=0;

int  n;


//n=a+b/c
//nc=ac+b
//b=nc-ac 只要推出来的b满足条件，a和c都满足条件则答案+1 
bool check(int a,int c)
{
	int b=n*c-a*c;
	
	if(!a || !c || !b)return false;
	
	memcpy(ever,had_use,sizeof had_use);//基于现有的情况下，不破坏原来的数组
	//那就拷贝一份，既能在原来之上操作，又能不破坏原来的记录 
	
	while(b)//取出每一位，用来更新用过的数字 
	{
		int t=b%10;
		b/=10;
		if(!t || ever[t])return false;
		ever[t]=1;
	}
	
	for(int i=1;i<=9;i++)if(!ever[i])return false;
	
	return true;
}

void dfs_c(int x,int a,int c)
{
	if(x>=10)return ;
	if(check(a,c))ans++;
	for(int i=1;i<=9;i++)
	{
		if(!had_use[i])
		{
			had_use[i]=1;
			dfs_c(x+1,a,c*10+i);
			had_use[i]=0;//回溯，避免下次的递归中出现错误 
		}
	}
}

void dfs_a(int x,int a)
{
	if(a>=n)return;
	if(a)dfs_c(x,a,0);//如果a满足条件，那么枚举c然后判断是否是成立的
	//0是c的大小 
	for(int i=1;i<=9;i++)//枚举一下当前能用哪些数字
	{
		if(!had_use[i])
		{
			had_use[i]=1;
			dfs_a(x+1,a*10+i);
			had_use[i]=0;//恢复现场，回溯一下 
		}	
	} 
}

int main()
{	
	//cout<<714*97;
	cin>>n;
	dfs_a(0,0);//第一个表示当前用了多少个数字，第二个参数表示当前的a是多少 
	cout<<ans;
	return 0;
}
