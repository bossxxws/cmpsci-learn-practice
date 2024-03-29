#include<bits/stdc++.h>

using namespace std;

string s;

unordered_map<string,string>pre;

unordered_map<string,char>h;

char oper[]="udlr";
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

unordered_set<string>st;

queue<string>q;
//2 3 4 1 5 x 7 6 8
//1 2 3 4 5 6 x 7 8 
//ullddrurdllurdruldr
// u d l r
bool bfs()
{
	string end="12345678x";
	q.push(s);
	st.insert(s);
	while(q.size())
	{
		auto t=q.front();
		if(t==end)return true;
		q.pop();
		auto cur=t;
		int k=t.find('x');
		int x=k/3;
		int y=k%3;

		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			swap(t[k],t[nx*3+ny]);
			if(nx>=0 && ny>=0 && nx<=2 && ny<=2 && pre.find(t)==pre.end())
			{
				q.push(t);
				pre[t]=cur;
				h[t]=oper[i];
			}
				
			swap(t[k],t[nx*3+ny]);
		}
	}
	return false;
}


int main()
{
	string res;
	for(int i=0;i<9;i++)
	{
		char c;
		cin>>c;
		s+=c;	
	} 
	
	if(!bfs())cout<<"unsolvable";
	else
	{
		string t="12345678x";
		while(true)
		{

			if(t==s)
			{
				break;
			}
			res=h[t]+res;
			t=pre[t];
		}

	}
	cout<<res;
	return 0;
}
