#include<bits/stdc++.h>

using namespace std;

int n,l,r,t; 

const int N=603;

int g[N][N];

int res=0;
/*

我在这里犯了个错误卡了半天，这个错误就是边界值应该取1而不是0
此外，用max取值将会方便更多 eg:x1=max(x1,1); 

*/

//二维矩阵前缀和

int sf(int x1,int y1,int x2,int y2)
{
	return g[x2][y2]-g[x2][y1-1]-g[x1-1][y2]+g[x1-1][y1-1];
}

int main()
{
	cin>>n>>l>>r>>t;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>g[i][j];
// 			cout<<g[i][j]<<" ";
		}
// 		cout<<endl;
	}
	//前缀和处理
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
// 			cout<<g[i][j]<<" ";
		}
// 		cout<<endl;
	} 
	
	//计算
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x1=i-r;if(x1<1)x1=1;
			int y1=j-r;if(y1<1)y1=1;
			int x2=i+r;if(x2>n)x2=n;
			int y2=j+r;if(y2>n)y2=n;//处理好边界
			
// 			cout<<sf(x1,y1,x2,y2)<<endl;
			
			int tmp=sf(x1,y1,x2,y2);
			
			if(tmp<=t*((x2-x1+1)*(y2-y1+1)))res++;
			 
		}
	} 
// 	for(int i=0;i<=n;i++)
// 	{
// 	    for(int j=0;j<=n;j++)
// 	    {
// 	        cout<<g[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
// 	cout<<sf(2,2,3,2);

	cout<<res;
	return 0;
} 
