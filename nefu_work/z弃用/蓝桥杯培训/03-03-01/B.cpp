#include<bits/stdc++.h>

using namespace std;

int N,K,P;
//N人

//K张纸牌
//其中K/N张good
//剩下的全是bad

//每次洗P张牌 
 
//算M次小明的位置

queue<int> q;
 
int main()
{
	scanf("%d%d%d",&N,&K,&P);
	
	for(int i=1;i<=K;i++)q.push(i);
	
	int m=K/N;
	
	priority_queue<int,vector<int>,greater<int>> pri;
	
	//输出m次	
	int cnt=0;//搞到所有好运牌为止 
	while(cnt<m)
	{
		int n=N-1;
		
		//一轮 
		while(n>0)
		{
			//发牌 
			n--;
			q.pop();
			//洗牌 
			for(int i=0;i<P;i++)
			{
				int a=q.front();q.pop();
				q.push(a); 
			}
		}
		//轮到自己
		//cout<<q.front()<<endl;
		
		pri.push(q.front());
		
		q.pop();
		for(int i=0;i<P;i++)
		{
			int a=q.front();q.pop();
			q.push(a); 
		}
		cnt++;
	}
	
	while(pri.size())
	{
		cout<<pri.top()<<endl;
		pri.pop();
	}
	return 0;
}
