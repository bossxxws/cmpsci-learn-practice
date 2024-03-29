#include<bits/stdc++.h>
using namespace std;

int n,m;

typedef unsigned long long  ULL;

const int N=100010,P=131;//P用来p进制的表达 （131进制） 

char str[N];
ULL h[N],p[N];

//不能映射成0 
//假定不存在冲突的情况
//当p取131或1331的时候（这两个是经验值），q取成2的64次方，可以假定不会出现冲突（99.99%的情况下不会冲突）
//h[lr]=h[r]-h[l]*P**(l-r+1),为l到r之间的哈希值 

ULL get(int l,int r)
{
	return h[r]-h[l-1]*p[r-l+1];
}

int main()
{
	cin>>n>>m>>str+1;
	//预处理
	p[0]=1;
	for(int i=1;i<=n;i++)p[i]=p[i-1]*P; //每个位置的权重求出来 即为p的次方 
	for(int i=1;i<=n;i++)h[i]=h[i-1]*P + str[i];
	while(m--)
	{
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if (get(l1,r1)==get(l2,r2))cout<<"Yes"<<endl;
		else cout<<"No"<<endl; 
		
	}	
	
	return 0;
}
