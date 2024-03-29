#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

struct range
{
	int l,r;
}dat[N];

bool cmp(range a,range b)
{
	return a.l<b.l;
}

int main()
{
	//输入 线段 
	int star,end;
	cin>>star>>end;
	
	//输入n个区间 
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		dat[i]={l,r};
	}
	
	sort(dat,dat+n,cmp);	
		
	//经典的双指针模板
	//for + while 
	int st=star; 
	int res=0;
	bool f=false;
	for(int i=0;i<n;i++)
	{
		int j=i,ed=-2e9;
		while(j<n && dat[j].l<=st) 
		{
			ed=max(dat[j].r,ed);
			j++;//选出能覆盖st的最大右端点的组 
		}
		
		//ed最开始为负无穷，如果没更新则说明没有左端点小于star的区间，并且与star
		//比较，如果小于star就表示没有右端点大于star的区间 
		if(ed<st)
		{
			res=-1;
			break;
		}
		
		//更新st，成功用一个区间，res++ 
		st=ed;
		res++;
		
		if(st>=end)
		{
			f=true;
			break;
		} 
		
		i=j-1;
	} 
	
	if(!f)cout<<-1<<endl;
	else cout<<res<<endl;
	return 0;
}
