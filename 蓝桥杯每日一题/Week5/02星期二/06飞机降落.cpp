#include<bits/stdc++.h>

using namespace std;

int k,n; 

const int N=11;

bool st[N];

struct plane
{
	int t,d,l;
}p[N];

//u�Ѿ�����ķɻ����� 
//lΪ��һ�ܷɻ��Ľ���ʱ��  
bool dfs(int u,int last)
{
	if(u>=n)//����ɻ������ﵽ�����YES
	{
		//cout<<"YES"<<endl;
		return true;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!st[i])
		{
			st[i]=true;//��ǴӴ˿�ʼ���� 
			//��һ�ҷɻ����Խ����ʱ����Ͻ����ʱ�� 
			//��һ�ܷɻ��������ʱ��������������ʱ�� 
			//������ֵȡ���ֵ 
			if(p[i].t+p[i].d>=last)if(dfs(u+1,max(p[i].l+p[i].t,last+p[i].l)))return true;
			st[i]=false;//���� 	
		}
	}
	return false;
}

int main()
{
	cin>>k;
	while(k--)
	{
		cin>>n;
		memset(st,false,sizeof st);
		for(int i=0;i<n;i++)
		{
			int t,d,l;
			scanf("%d%d%d",&t,&d,&l);
			p[i].t=t;
			p[i].d=d;
			p[i].l=l;
		}
		
		bool t=dfs(0,0);
		if(t)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;	
} 
