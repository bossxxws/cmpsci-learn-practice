#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n,m;//�����Ͷ�������
int rooms[N]; //ÿ��ɽ���ҵ����� 

struct qes
{
	int d,s,t;//���� ��ʼ ���� 
}Q[N];

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&rooms[i]);
	}
	
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		Q[i]={a,b,c};
	}
	
	int mem;
	bool f=true;
	
	
	for(int i=1;i<=m;i++)
	{
		int t=Q[i].d;//��i������ 
		for(int j=Q[i].s;j<=Q[i].t;j++)
		{
		    //cout<<rooms[3]<<endl;
			rooms[j]-=t;
			if(rooms[j]<0)
			{
			    //cout<<j<<endl;
			    //cout<<rooms[j]<<endl;
				mem=i;
				f=false;
				break;
			}
		}
		if(!f)break;
	}
	
	if(f)cout<<0<<endl;
	else cout<<-1<<endl<<mem<<endl;
	
	return 0;
} 
