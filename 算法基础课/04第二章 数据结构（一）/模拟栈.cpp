#include<iostream>

#include<string>

using namespace std;

const int N=100010;

int stk[N],tt=0;


int main()
{
	int M;
	cin>>M;
	while(M--)
	{
		string op;
		cin>>op;
		if(op=="push")
		{
			int x;
			cin>>x;
			stk[++tt]=x;
		} 
		else if(op=="pop")tt--;
		else if(op=="empty")
		{
			if(tt>0)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
		else if(op=="query")cout<<stk[tt]<<endl;
	}
	return 0;
}
