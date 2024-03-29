#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

typedef long long LL;

int n;
int l[N],r[N],p[26];

char s[N];

int main()
{
	scanf("%s",s+1);
	
	int n=strlen(s+1);
	//当字符x左边没有重复的x的时候相当于在0这个位置有一个x（字符串的下标从1开始）
	//这里省略了设为0的步骤：for(int i=0;i<26;i++)p[i]=0;
	//因为数组初始本来都是0 
	for(int i=1;i<=n;i++)
	{
		int t=s[i]-'a';
		l[i]=p[t];
		p[t]=i;
	}
	
	for(int i=0;i<26;i++)p[i]=n+1;
	//每个字符的右边上一个第一次出现下标初始值设为n+1 
	//因为当字符y右边没有重复的y的时候相当于在n+1这个位置有一个y（字符串最后一个下标为n） 
	for(int i=n;i>=1;i--)
	{
		int t=s[i]-'a';
		r[i]=p[t];
		p[t]=i;
	}
	LL res=0;
	for(int i=1;i<=n;i++)
	{
		res+=(LL)(i-l[i])*(r[i]-i);
	}
	cout<<res; 
	return 0;
} 
