#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

typedef long long LL;

int a[N];//a是原数组 

LL tr1[N];//维护b【i】的前缀和 

LL tr2[N];//维护i*b【i】的前缀和

int n,m; 

int lowbit(int x)
{
	return x&-x;
}

//这里因为要处理两个数组，所以加上数组参数
void add(LL tr[],int x,LL v)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		tr[i]+=v;	
	}	
} 

LL query(LL tr[],int x)
{
	LL res=0;
	for(int i=x;i;i-=lowbit(i))
	{
		res+=tr[i];
	}
	return res;
}

LL presum(int x)//求前缀和Sx（x及之前的和） （Sn=（∑bi） * （n+1） - （∑(i*bi)）） 
{
	LL a = query(tr1,x)*(x+1);
	LL b=query(tr2,x);
	return a-b;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	//形成树状差分数组 
	for(int i=1;i<=n;i++)
	{
		int b=a[i]-a[i-1];
		add(tr1,i,b);
		add(tr2,i,(LL)b*i);
	}	
	
	while(m--)
	{
		char op[1];
		scanf("%s",op);
		if(op[0]=='C')
		{
			int l,r,v;
			scanf("%d%d%d",&l,&r,&v);
			
			//b[l]+=v b[r+1]-=v
			add(tr1,l,v);add(tr1,r+1,-v);
			//b[l]+=l*v b[r+1]-=l*v
			add(tr2,l,(LL)l*v);add(tr2,r+1,(LL)-(r+1)*v);
			
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			
			cout<<presum(r)-presum(l-1)<<endl;
		}
	}
	
	return 0;
} 
