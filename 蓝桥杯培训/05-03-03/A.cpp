#include<bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin>>n;	
		 
	queue<string>q;
	
	for(int i=0;i<n;i++)
	{
		string op;
		cin>>op;
		q.push(op);
	} 
	
	int cnt=0;
	int ele=0;
	bool f=true;
	while(!q.empty())
	{
		string s=q.front();
		q.pop();
		
		if(s=="push")
		{
			cnt++;
			ele++;
		}
		else if(s=="pop")
		{
			cnt++;
			if(ele==0)
			{
				f=false;
				break;
			}
			else
			{
				ele--;
			}
		}
		else if(s=="top")
		{
			cnt++;
			if(ele==0)
			{
				f=false;
				break;
			}
		}
		else
		{
			cnt++;
			ele=0;
		}
	}
	if(f)cout<<"Yes"<<endl<<ele;
	else cout<<"No"<<endl<<cnt;
	return 0;
} 
