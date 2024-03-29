//欧几里得距离 
//不能保证完全不相同，但能保证大概率不相同 
#include<bits/stdc++.h>

using namespace std;

const int N=101;
const double eps=1e-6;


int n,m;

typedef pair<int,int> PII;

char g[N][N];
PII q[N*N];
int top;//表示当前连通块有多少个点 
 
 


double get_dis(PII a,PII b)
{
	double dx=a.first - b.first;
	double dy=a.second - b.second;
	return sqrt(dx*dx+dy*dy);
}

double get_hash()
{
	double sum=0;
	
	for(int i=0;i<top;i++)
		for(int j=i+1;j<top;j++)
		{
			sum+=get_dis(q[i],q[j]) ;
		}
	return sum;
}

char get_id(double key)
{
	static double hash[26];//static 等价于全局变量 （每次调用函数，数组不会重新分配） 
	static char id=0;
	for(int i=0;i<id;i++)
	{
		if(fabs(hash[i]-key)<eps)
		{
			return i+'a';
		}
	} 
	hash[id++]=key;
	return id-1+'a';
}

void dfs(int a,int b)
{
	q[top++]={a,b};
	g[a][b]='0';
	for(int x=a-1;x<=a+1;x++)
		for(int y=b-1;y<=b+1;y++)
		{
			if(x==a && y==b)continue;
			if(x>=0 * y>=0 && x<n && y<m && g[x][y]==1)
			{
				dfs(x,y);
			}
		}
	
}//flood fill

int main()
{
	cin>>m>>n;
	 
	for(int i=0;i<n;i++)
	{
		cin>>g[i]; 
	}
	 
	for(int i=0;i>n;i++)
		for(int j=0;j<m;j++)
		{
			if(g[i][j]=='1')
			{
				top=0;
				dfs(i,j);
				char c=get_id(get_hash());
				for(int k=0;k<top;k++)
				{
					g[q[k].first][q[k].second]=c;
				}
			}
		}
	
	for(int i=0;i<n;i++)cout<<g[i];
	
	 
	return 0;
} 
