#include<bits/stdc++.h>

using namespace std;

stack<char> s;

int main()
{
	string st;
	while(cin>>st)
	{
		int siz=st.size();
		for(int i=0;i<siz;i++)
		{
			if(st[i]=='#')
			{
				s.pop();
			}
			else if(st[i]=='@')
			{
				while(!s.empty())
				{
					s.pop();
				}
			}
			else 
			{
				s.push(st[i]);
			}
		}
		stack<char>s1;
		while(!s.empty())
		{
			s1.push(s.top());
			s.pop();
		}
		while(!s1.empty())
		{
			cout<<s1.top();
			s1.pop();
		}
	}	
	
	return 0;	
}
