#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=5003;

int s[N][N];

int n,m;

int main()
{
	cin>>n>>m;// m * m ��ը���ķ�Χ 
	
	m=min(5002,m);
	//cout<<"____"<<endl;
	for(int i=1;i<=n;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		//ƫ��һ�£����ü���
		s[++x][++y]+=w;//ע����  "+="  ������Ϊ�п����ظ�Ŀ���ж����ֵ 
	}
	//cout<<"____"<<endl;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
		}
	
	int res=0;
	//cout<<"____"<<endl;
	for(int i=m;i<N;i++)
		for(int j=m;j<N;j++)
		{
			res=max(res,s[i][j]-s[i-m][j]-s[i][j-m]+s[i-m][j-m]);	
		}
	
	cout<<res<<endl;
	return 0;
}
