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
	int n;
	cin>>n;
	
	//读入数组
	for(int i=0;i<n;i++)
	{
		int l,r;
		cin>>l>>r;
		dat[i]={l,r};
	} 
	
	sort(dat,dat+n,cmp);
	
	priority_queue<int,vector<int>,greater<int>> heap;//小根堆定义方式
	//小根堆维护区间内最小的r 
	
	//heap存的是每个组里面最大的右端点
	for(int i=0;i<n;i++)
	{
		auto t=dat[i];
		//最是拿heap.top()比较（最大右端点最靠前的组，这样能并入组的能有更多，更贪心）
		//并入后原来组的最大右端点肯定变成最新并入区间的最大右端点了，所以将原来的弹出
		//然后把新的加入
		//并入后堆会进行排序，还是挑出拥有最小最大右端点的组
		
		//不能放入组
		if(heap.empty() || t.l<=heap.top())heap.push(t.r);
		else
		{
		    //放入组中并更新max_r
		    heap.pop();//把原来的最大右端点去掉
		    heap.push(t.r);//加入新的最大右端点
		} 
	}
	cout<<heap.size()<<endl;

	return 0;
}
