#include<bits/stdc++.h>

using namespace std;

int m,n;
int k;

int main()
{
	cin>>m>>n;
	cin>>k;
	
	queue<int>ma;
	queue<int>na;
	
	for(int i=1;i<=m;i++)ma.push(i);
	for(int i=1;i<=n;i++)na.push(i);
	
	for(int i=0;i<k;i++)
	{
		int a=ma.front();ma.pop();
		int b=na.front();na.pop();
		
		cout<<a<<" "<<b<<endl;
		
		ma.push(a);
		na.push(b);
	}

	return 0;
} 
