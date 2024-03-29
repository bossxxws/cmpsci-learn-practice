//每次加上1，最后处理询问的时候%2，奇数就是黑，偶数就是白(不管怎么加都是这样,因为一开始0都是白色)
#include<bits/stdc++.h>

using namespace std;

int n,m;

const int N=2003;

int a[N][N],b[N][N];

void insert(int x1,int y1,int x2,int y2,int c)
{
	b[x1][y1]+=c;
	b[x2+1][y1]-=c;
	b[x1][y2+1]-=c;
	b[x2+1][y2+1]+=c;
}

int main()
{
	cin>>n>>m;
	
	//for(int i=1;i<=n;i++) 
		//for(int j=1;i<=n;j++)
		//{
			//scanf("%d",&a[i][j]);
			//insert(i,j,i,j,a[i][j]);
	//	}//将a差分进b
		
	//询问
	for(int i=1;i<=m;i++)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		insert(x1,y1,x2,y2,1);
	}	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
			if(!(b[i][j]%2))cout<<0;
			else cout<<1;	
		}
		cout<<endl;
	}

	return 0;
} 
