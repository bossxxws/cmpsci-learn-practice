#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=1e5+10;

int x[N],y[N];//存储x、y坐标 

int n;
//相当于 n 个相同的数求前缀和 
// 1 1 1 1 2 相当于 三项  （i-stx-1）*（i-stx-1+1）就是这么来的 
// 3+2+1

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	} 
	
	sort(x,x+n);
	sort(y,y+n);
	
	int stx=0,sty=0;
	
	LL sum=0;
	
	for(int i=1;i<n;i++)
	{
		if(x[stx]!=x[i])
		{
			sum+=(LL)(i-stx)*(i-stx-1)/2;//（首项 + 末项） * 项数/2 
			stx=i;
		}
		
		if(y[sty]!=y[i])
		{
			sum+=(LL)(i-sty)*(i-sty-1)/2;
			sty=i;
		}
	}
	//最后可能到n-1的时候还没算完 比如说 9 9 9 9 一直到n-1最后一个
	//x【i】没有不等于 x【stx】 
	//就算是 9 9 9 9 10形式的，用以下方式算也不会错 
	//因为第n个不存在，到第n个也相当于一定不等于前面的，大不了sum+=0 
	
	sum+=(LL)(n-stx)*(n-stx-1)/2;
	sum+=(LL)(n-sty)*(n-sty-1)/2;
	
	cout<<sum<<endl;
	return 0;
}
