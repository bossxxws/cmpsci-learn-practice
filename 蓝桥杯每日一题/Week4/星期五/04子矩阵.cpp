#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int n,m,a,b; 

int g[N][N],minr[N][N],maxr[N][N]; 

int q[N];

typedef long long LL;

const int MOD=998244353;

void getmin(int a[],int b[],int total,int lenth)
{
	int tt=-1,hh=0;
	for(int i=0;i<total;i++)
	{
		//判断元素是否滑出窗口 
		if(hh<=tt && q[hh]<=i-lenth)hh++;
		//判断新元素和旧元素的大小关系确保队列单调
		while(hh<=tt && a[i]<=a[q[tt]])tt--; 	
		//入队 
		q[++tt]=i;
		//把最值交给存储数组 （队头一定是最小的） 
		if(i>=lenth-1)b[i]=a[q[hh]];//i>=k-1表示滑动窗口形成
		
	}
}


void getmax(int a[],int b[],int total,int lenth)
{
	int tt=-1,hh=0;
	for(int i=0;i<total;i++)
	{
		
		if(hh<=tt && q[hh]<=i-lenth)hh++;
		
		while(hh<=tt && a[i]>=a[q[tt]])tt--;
		
		q[++tt]=i;
		
		//队头一定是最大的，赋值给b 
		if(i>=lenth-1)b[i]=a[q[hh]];
	}
}

int main()
{
	cin>>n>>m>>a>>b;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)scanf("%d",&g[i][j]);
	//for(int i=0;i<n;i++)
		//for(int j=0;j<m;j++)printf("%d",g[i][j]);
	//预处理出来每一行中滑动窗口的最值 
	for(int i=0;i<n;i++)
	{
		getmin(g[i],minr[i],m,b);
		getmax(g[i],maxr[i],m,b);
	}
	
	 
	int res=0;
	
	int A[N],B[N],C[N];
	
	for(int i=b-1;i<m;i++)//固定好列区间 
	{
		for(int j=0;j<n;j++)A[j]=maxr[j][i];//每行：把每个窗口最大的数取出来
		getmax(A,B,n,a);//存到B中 
		for(int j=0;j<n;j++)A[j]=minr[j][i];//每行：把每个窗口最小的数取出来 
		getmin(A,C,n,a);//存到C中 
		for(int j=a-1;j<n;j++)	
		{
			res=(res+(LL)B[j]*C[j])%MOD;
		}
	}
	cout<<res;
	return 0;
}
