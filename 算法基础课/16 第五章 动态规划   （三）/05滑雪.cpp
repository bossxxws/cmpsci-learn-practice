//���仯����
//ÿһ����̬�滮���ⶼ�����õݹ���д 

//���仯������һ��ǰ����ͼ��һ������ͼ��ͼ�в����ڻ���
 
//����һ�������ڻ�
 
/*
״̬��ʾ�� 	
	���ϣ�f[N][N]��ʾ���д�i��j��ʼ����·��
	���ԣ���켣MAX
	
״̬���㣺
	f[i][j]��ʾ�����е�·�����Է�Ϊ���ࣺ���ϻ������»������󻬡����һ� 
	��������ֵȡmax����f[i][j]�����ֵ 

*/ 

#include<bits/stdc++.h>

using namespace std;

const int N=302;

int n,m;	

int h[N][N];

int f[N][N];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

//�����Ĺ���
int dp(int x,int y)
{
	int &v=f[x][y];//���ú�����дv�ĵط��൱��дf[x][y]
	
	if(v!=-1)return v;//���ѹ���ֱ�ӷ���
	
	//��СΪ1������1������---��ǰ���� 
	v=1;
	
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			//λ�úϷ��Ҹ߶ȵ������ 
			if(nx>=1 && ny>=1 && nx<=n && ny<=m && h[nx][ny]<h[x][y])
			{
				v=max(v,dp(nx,ny)+1); 
			}	
		} 
	return v;
}

int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&h[i][j]);
		}
	//һ����·�� 
	
	//1�������е�״̬��ʼ��Ϊ-1����ʾÿ��״̬��û�б������ 

	memset(f,-1,sizeof f);
	
	int res=0;
	
	//2����ʼÿ��������
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)//��ÿһ������� 
		{
			res=max(res,dp(i,j));
		}
	
	cout<<res;
	
	return 0;
}

/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

25

*/
