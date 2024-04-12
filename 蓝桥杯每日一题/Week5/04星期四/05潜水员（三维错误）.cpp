#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int n,m,K;

struct node
{
	int o,n,w;
}tool[N];

int f[81][81][N]; 

int main()
{
	cin>>m>>n;//所需要的氧和氮 
	
	cin>>K;//气缸的个数 
	
	for(int i=1;i<=K;i++)
	{
		scanf("%d%d%d",&tool[i].o,&tool[i].n,&tool[i].w);//读入该气缸的氧气、氮气、重量	
	}
	
	memset(f,0x3f,sizeof f);//求最小值要把所有值初始化为无穷大 
	
	f[0][0][0]=0;
    f[0][0][1]=0;
	int res=1<<31-1;
	
	for(int k=1;k<=K;k++)//枚举气缸 for(int k=1;k<=K;k++)//枚举气缸 
    	    for(int i=m;i>=0;i--)//枚举氧气 
    		    for(int j=n;j>=0;j--)//枚举氮气 
        		{
            
        				//f[i][j][k]=f[i][j][k-1];//k-1个尚能满足i和j，k个更能满足i和j了 
        				//if(i>=tool[i].o)f[i][j][k]=min(f[i][j][k],f[i-tool[i].o][j][k]+node[i].w);
        				//if(i>=tool[i].n)f[i][j][k]=min(f[i][j][k],f[i][j-tool[i].n][k]+node[i].w);
        				f[i][j][k]=min(f[i][j][k],f[max(0,i-tool[k].o)][max(0,j-tool[k].n)][k-1]+tool[k].w);
        			
        		}
        		
	//cout<<f[m][n][K];
	
	for(int i=1;i<=K;i++)res=min(f[m][n][i],res);
	
	cout<<res;
	
	return 0;
} 
/*
5 60
5
3 36 120
10 25 129
5 50 250
1 45 130
4 20 119

249
*/
