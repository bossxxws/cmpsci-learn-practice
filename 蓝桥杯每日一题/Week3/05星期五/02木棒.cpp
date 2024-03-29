#include<bits/stdc++.h>

using namespace std;

const int N=70;

int n;

int len,sum;
int a[N];
bool st[N];//��¼״̬ 
//cur��ʾ��ǰ�ĳ���
//u��ʾƴ�ӵĸ��� 
//start��ʾ�ӵڼ�����ʼƴ 
bool dfs(int u,int cur,int start)
{
	if(u*len==sum)return true;//ƴ�����е� 
	if(cur==len)return dfs(u+1,0,0);
	for(int i=start;i<n;i++)
	{
		if(st[i])continue;
		if(cur+a[i]<=len)
		{
			st[i]=true;//��ʾ��i���Ѿ��ù��� 
			if(dfs(u,cur+a[i],i+1))return true;
			st[i]=false;
		}
		if(!cur || cur+a[i]==len)return false;//�����ǰ��ƴ��ľ�����������һ��Ʒ�õ�ľ�� 
		int j=i+1;
		while(j<n && a[j]==a[i])j++;//����������ͬ��ľ�� 
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
