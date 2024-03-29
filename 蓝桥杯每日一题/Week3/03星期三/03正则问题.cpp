#include<bits/stdc++.h>

using namespace std;

int k=0;

string s; 

//((xx|xxx)x|(x|xx))xx 
//6
int dfs()
{
	int res=0;
	while(k<s.size())
	{
		if(s[k]=='(')
		{
			k++;
			res+=dfs();
			k++;
			
		}
		else if(s[k]==')')
		{
			break;
		}
		else if(s[k]=='|')
		{
			k++;
			res=max(res,dfs());
		}
		else
		{
			k++;
			res++;
		}
	}
	return res;
}

int main()
{
	cin>>s;
	
	int res=dfs();
	cout<<res;
	return 0;
}
