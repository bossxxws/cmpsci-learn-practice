#include<bits/stdc++.h>

using namespace std;

const int N=5004;

int g[N][N];
 
int res=0;

//��x1 y1 �����Ϊ���Ͻǣ���x2 y2 �����Ϊ���½ǵ� һ���Ӿ����ڲ����ܺ�
int getas(int x1,int y1,int x2,int y2)
{
	//��ǰ׺������С������ļ�һ
	//���֣� �������ļ�һ 
	return g[x2][y2]-g[x1-1][y2]-g[x2][y1-1]+g[x1-1][y1-1];	
} 

int main()
{
	int n,r;
	cin>>n>>r;
	r=min(r,5002);//�߳�������N�����Ա�ը����ȡһ��min 
	//�������
	for(int i=1;i<=n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		g[x+1][y+1]+=w;

	}	
	for(int x=1;x<N;x++)
		for(int y=1;y<N;y++)
		{
			//cout<<x<<endl;
			//��ǰ׺�ͣ���һ 
			g[x][y]+=g[x-1][y]+g[x][y-1]-g[x-1][y-1];
		}
	//ö������ 
	//�̶���� 
	for(int i=1;i<N-r;i++)
		for(int l=1;l<N-r;l++)//�̶��Ͻ� 
		{
            //�����γɣ����Ͻ�Ϊi-r l-r ���½�Ϊi��l
			res=max(res,getas(i,l,i+r-1,l+r-1));//r=1ʱ�൱�������Լ��ľ���ǰ׺��
		}
	cout<<res;
	return 0;
}
