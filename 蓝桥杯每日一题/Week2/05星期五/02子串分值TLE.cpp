//经验证这个暴力枚举法是对的 
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

typedef long long LL;

int n;

string s;

LL work(int x,int y)
{
	int t=0;
	int st[N];
	for(int i=x;i<=y;i++)
	{
		//cout<<i;
		st[s[i]-'a']++;
		//cout<<st[s[i]-'a']<<"////";
	}
	for(int i=0;i<26;i++)
	{
	//	cout<<st[i]<<endl;
		if(st[i]==1)t++;
	}
	//cout<<t;
	memset(st,0,sizeof(st));
	return t;
}

int main()
{
	LL res=0;
	
	cin>>s;
	s=" "+s;
	int n=s.size();
	//for(int i=1;i<=n;i++)
	//{
	//	cout<<s[i];
	//}
	
	for(int i=1;i<=n-1;i++)//枚举每个子串 
	{
		for(int j=i;j<=n-1;j++)
		{
			res+=work(i,j);//表示处理这一段 
			//cout<<i<<" "<<j<<endl;
		}
	}
	//cout<<work(1,5);
	cout<<res;
	return 0;
}
