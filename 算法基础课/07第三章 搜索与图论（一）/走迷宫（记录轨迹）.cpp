//���·���⣨ֻ�б�Ȩ����1��ʱ�򣬲�����bfs��ʱ�临�ӶȱȽϸߣ��� 
//���·�������DP���� 
//DP������һ��û�л����ڵ����·����
 
#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> PII;
const int N=101;
int n,m;
int g[N][N];//��ͼ 
int d[N][N];//��㵽�յ�ľ��� 
PII q[N*N],Prev[N][N];//���ꡢ��¼֮ǰ��λ�� 

int bfs()
{
	int hh=0,tt=0;
	q[0]={0,0};
	memset(d,-1,sizeof d);//-1����û���߹� 
	d[0][0]=0; 
	int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	
	while(hh<=tt)
	{
		auto t=q[hh++];//ÿ��ȡ����ͷ 
		for(int i=0;i<4;i++)
		{
			int x=t.first+dx[i],y=t.second+dy[i];//����һ��
			if(x>=0 && x<n && y<m && y>=0 && g[x][y]==0 && d[x][y]==-1)//��Խ�硢�����ߡ�����û���߹�
			{
				d[x][y]=d[t.first][t.second]+1;
				Prev[x][y]=t;//x��y���Ѿ��߹���t������˵t��x��y֮ǰ��״̬ 
				q[++tt]={x,y};//���ȥ��ǰ�߹�������
			}
		}	
	}
	int x=n-1,y=m-1;
	while(x || y)
	{
		cout<<x<<" "<<y<<endl;
		auto t=Prev[x][y];
		x=t.first,y=t.second;
	}
	return d[n-1][m-1];
}

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>g[i][j];
			
	cout<<bfs()<<endl;
	return 0;
}
