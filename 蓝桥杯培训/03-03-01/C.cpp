#include<bits/stdc++.h>

using namespace std;

int n,m;
//n个小朋友，报道m离开 

queue<int>q;

int main()
{
	cin>>n>>m;
	
	//形成队列，相当于一个环形队列 
	for(int i=1;i<=n;i++)q.push(i);
	
	int cnt=0;//报数 
	
	while(q.size()!=1)
	{
		if((cnt+1)!=m)
		{
			cnt++;
			
			//排到队尾 	
			int a=q.front();
			q.pop();q.push(a);
		}
		if((cnt+1)==m)
		{
			cnt=0;
			q.pop(); //离开 
		}
	}

	cout<<q.front();
	
}
