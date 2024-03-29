#include<bits/stdc++.h>

using namespace std;

const int N=70;

int n;

int len,sum;
int a[N];
bool st[N];//记录状态 
//cur表示当前的长度
//u表示拼接的个数 
//start表示从第几根开始拼 
bool dfs(int u,int cur,int start)
{
	if(u*len==sum)return true;//拼成所有的 
	if(cur==len)return dfs(u+1,0,0);
	for(int i=start;i<n;i++)
	{
		if(st[i])continue;
		if(cur+a[i]<=len)
		{
			st[i]=true;//表示第i根已经用过了 
			if(dfs(u,cur+a[i],i+1))return true;
			st[i]=false;
		}
		if(!cur || cur+a[i]==len)return false;//如果当前在拼新木棍或者是最后一根品好的木棍 
		int j=i+1;
		while(j<n && a[j]==a[i])j++;//跳过长度相同的木棍 
		i=j-1;
	}
	return false;
}

int main()
{
	while(cin>>n,n!=0)
	{
		len=sum=0;
		memset(st,false,sizeof st);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];	
			sum+=a[i];
			len=max(len,a[i]);
		} 
		
		sort(a,a+n,greater<int>());
		while(true)
		{
			if(sum%len==0 && dfs(0,0,0))
			{
			    cout<<len<<endl;
			    break;
			}
			len++;
		}
	}
	
	
	return 0;	
} 
