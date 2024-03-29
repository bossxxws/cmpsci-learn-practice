#include<bits/stdc++.h>

using namespace std;

string start;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

//2 3 4 1 5 x 7 6 8

//19
 
int bfs(string start)
{
	//if(start==end)return d[] 不小心写递归了
	string end="12345678x";
	
	unordered_map<string,int>d;
	
	d[start]=0;//初始步数为0;
	
	queue<string>q;
	q.push(start);
	
	while(q.size())
	{
		string t=q.front();
		q.pop();
		
		int distance=d[t];
		//int cnt1=0;
		//for(int i=0;i<3;i++)
		//{
			//for(int j=0;j<3;j++)
			//{
				//cout<<t[cnt1++]<<" ";
			//}
			//cout<<endl;
		//}
		//cout<<endl;
		//cout<<d[t]<<endl;
		if(t==end)return distance;
		
		int k=t.find('x');
		
		int x=k/3;
		int y=k%3;//转化出'x'的位置 
		
		for(int i=0;i<4;i++)
		{

			
			int nx=x+dx[i];
			int ny=y+dy[i];
			//cout<<dx[i]<<" "<<dy[i]<<endl;
			//cout<<nx<<" "<<ny<<endl;
			if(nx>=0 && nx<=2 && ny>=0 && ny<=2  )
			{
				//cout<<k<<" "<<nx*3+y<<endl;
				swap(t[k],t[nx*3+ny]);
				//cout<<"new"<<endl; 

				if(!d.count(t))
				{	
					d[t]=distance+1;
					q.push(t);
				}

				swap(t[k],t[nx*3+ny]);
			}	
		}
		//cout<<-1;
	} 
	return -1;
	
}

int main()
{
	string start="";
	
	for(int i=0;i<9;i++)
	{
		char c;
		cin>>c;
		start+=c;
	}

	cout<<bfs(start);
		
	return 0;	
} 
