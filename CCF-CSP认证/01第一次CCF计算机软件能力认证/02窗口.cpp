#include<bits/stdc++.h>

using namespace std;

int n,m; 

const int N =12;
int g[N][6];

bool check(int x,int y,int idx)
{
	int x1=g[idx][1];
	int y1=g[idx][2];
	int x2=g[idx][3];
	int y2=g[idx][4];
	if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
	{
		cout<<g[idx][5]<<endl;
		//��ʼ�������²�λ�ã�idx��Ϊn����idx����Ķ�Ҫ��һ 
		//Ҳ������idx����Ķ�����ƽ��һ��λ��
		int t[5];//���� ��ǰ������� 
		for(int i=1;i<=5;i++)
		{
			t[i]=g[idx][i];
		} 
		for(int i=idx;i<n;i++)
		{
			for(int j=1;j<=5;j++)
			{
				g[i][j]=g[i+1][j];//����ı����������� 
			} 
		} 
		
		//����������Ļ�����,��������ı������ҳ�� 
		for(int i=1;i<=5;i++)
		{
			g[n][i]=t[i];
		}
		return true;
	}
	return false;
}
int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		g[i][5]=i;//���ڱ�� ���Խ��Խ������ 
		cin>>g[i][1]>>g[i][2]>>
		g[i][3]>>g[i][4];	
	}

	for(int i=1;i<=m;i++)//�����ѯ
	{
		//������λ��
		int x,y; 
		cin>>x>>y;
		bool flag=false;
		for(int i=n;i>=0;i--)//�����������Ĵ��� 
		{
			//�ж��Ƿ��ڵ�ǰ����������
			if(check(x,y,i))
			{
//				cout<<"idx: "<<i<<endl;
				flag=true;
				break;
			}
		}
		if(!flag)cout<<"IGNORED"<<endl;
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=5;j++)cout<<g[i][j]<<" ";
//		cout<<endl;
//	}
//	
//	cout<<check(4,4,1)<<endl;
	
	return 0;
} 
