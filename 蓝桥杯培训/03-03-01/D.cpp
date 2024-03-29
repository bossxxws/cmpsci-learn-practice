#include<bits/stdc++.h>

using namespace std;

int n,m,t;
 
queue< pair<string,int> >q;

int main()
{
	//n人，m是开始的人的编号，t是他开始报的数字 
	cin>>n>>m>>t;
	
	//录入身份 
	for(int i=1;i<=n;i++)
	{
		string name;
		cin>>name;
		
		pair<string,int> pi={name,i};
		q.push(pi);
	}
	
	//调整到第m个人 
	for(int i=1;i<m;i++)
	{
		auto p=q.front();
		q.pop();q.push(p);
	}
	//cout<<"----11"<<q.front().first<<endl;
	while(q.size()!=1)
	{
		//开始报数 
		if(t%7==0 || t%10==7)
		{
			//cout<<"---"<<endl<<q.front().first<<t<<endl;
			q.pop();//离开 
			t++; 
		}
		else
		{
			pair<string,int> px=q.front();
			q.pop();q.push(px);
			t++;
		}
	}
	
	cout<<q.front().first;
	return 0;
}
