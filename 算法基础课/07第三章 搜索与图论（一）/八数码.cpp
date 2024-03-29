#include<bits/stdc++.h>

using namespace std;

int bfs(string start)
{
	string end="12345678x";
	
	queue<string> q;
	unordered_map<string,int> d;
	
	q.push(start);
	d[start]=0;//最开始起点到起到距离为0
	
	int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	
	while(q.size())
	{
		auto t=q.front();
		q.pop();
		
		int distance = d[t];
		
		if(t==end) return distance;//如果已经是最终状态则直接返回 
		
		//状态转移
		int k=t.find('x');
		int x=k/3,y=k%3;//转化出'x'的位置
		
		for(int i=0;i<4;i++)
		{
			int a=x+dx[i],b=y+dy[i];//（a，b）是（x，y）上下左右的一个位置
		 
			if(a>=0 && a<3 && b>=0 && b<3)
			{
			    swap(t[k],t[a*3+b%3]);//这里%不%3都行 
				//（x，y）的下标是k ，而（a，b）的下标是（a*3+b）
				
				if(!d.count(t))
				{
					d[t]=distance + 1;
					q.push(t);//存下此时的字符串（可转化为九宫格）状态
				} 
				 
				swap(t[k],t[a*3+b%3]);//还原状态(为了接下来往上下左右其他地方走)，这里%不%3都行 
				
			}
		}
	} 
	return -1;
	
	
}

int main()
{
	string start;
	for(int i=0;i<9;i++)
	{
		char c;
		cin>>c;
		start+=c;
		 
	}
	
	cout<<bfs(start)<<endl;
	return 0;
	
} 
