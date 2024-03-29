#include<bits/stdc++.h>

using namespace std;

queue<int>a;
queue<int>aim;

stack<int>aux;

int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)a.push(i);//a ³õÊ¼»¯»ð³µ 1234
	
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		aim.push(t);
	}//aim 3241
	
	while(aim.size())
	{
		if(!a.empty() && !aux.size())
		{
			int t=a.front();
			aux.push(t);
			a.pop();
			cout<<'A';
		}
		while(!a.empty() && aux.top()!=aim.front())
		{
			int t=a.front();
			aux.push(t);
			cout<<'A';
			a.pop();
		}
		while(!aux.empty() && aim.front()==aux.top())
		{
			aux.pop();
			aim.pop();
			cout<<'B';
		}
	}
	
	return 0;
}
