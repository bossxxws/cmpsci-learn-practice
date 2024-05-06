#include<bits/stdc++.h>

using namespace std;

const int N=3000;

int n; 

int a[N];

int b[N];

int f[N][N];

//f[i][j]代表所有a[1 ~ i]和b[1 ~ j]中以b[j]结尾的公共上升子序列的集合；
//f[i][j]的值等于该集合的子序列中长度的最大值；

int main()
{

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &b[i]);
    
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
			f[i][j]=f[i-1][j];
			
			if(a[i]==b[j])
			{
				int maxv=1;
				
				for(int k=1;k<j;k++)if(b[j]>b[k])maxv=max(maxv,f[i-1][k]+1);	
				f[i][j]=max(f[i][j],maxv);		
			}	
			
		}
	}
	int res=-1;
	
	
	for(int i=1;i<=n;i++)res=max(res,f[n][i]);
	
	cout<<res;
	
	return 0;
}
