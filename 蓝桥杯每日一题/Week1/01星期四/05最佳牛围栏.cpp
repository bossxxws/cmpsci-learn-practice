//一般平均值问题都可以转化为二分问题 

#include<bits/stdc++.h>

using namespace std;

int n,f;//总共n块地，每块需要至少包含f块地 

const int N=1e5+5;

double q[N]; 

//前缀和
double s[N]; 

bool check(double avg)
{
	//求出前缀和全部减去avg 
	for(int i=1;i<=n;i++)s[i]=s[i-1]+q[i]-avg;
	
	double mins=0; 
	//分为数个区间，每个区间求出最大值，如果大于0，就可以
	for(int k=f;k<=n;k++)
	{
		mins=min(mins,s[k-f]);//s[k-f]使得区间至少长度为f,并且记录需要减去的前缀和最小值
		if(s[k]-mins>=0)return true;
	} 

	return false;
}

int main()
{
	cin>>n>>f;
	
	double l=0;
	double r=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&q[i]);
		r=max(r,q[i]);
	}
	
	while(r-l>1e-5)
	{
		double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	
	
	cout<<(int)(r*1000);
	return 0;
}
