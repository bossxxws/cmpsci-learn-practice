#include<bits/stdc++.h>

using namespace std;

int main()
{
	string aim;
	cin>>aim;
	stack<char> s;
	bool f=true;
	for(int i=0;i<aim.size();i++)
	{
		if(aim[i]=='(' or aim[i]=='[')
		{
			s.push(aim[i]);
		}
		else if(aim[i]==')')
				
		{
			if(!s.empty() && s.top()=='(')
			{
				s.pop();	
			}	
			else
			{
				f=false;
				break;
			}
		} 
		else if(aim[i]==']')
		{
			if(!s.empty() && s.top()=='[')
			{
				s.pop();
			}
			else
			{
				f=false;
				break;
			}
		}
	}

	if(f && s.empty())cout<<"OK"<<endl;
	else cout<<"Wrong"<<endl;
	

	return 0;
}
