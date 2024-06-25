#include<bits/stdc++.h>

using namespace std;

stack<int> dirty;
stack<int> wash;
stack<int> dry;

void oper(int op,int t)
{
	//wash
	if(op==1)
	{
		while(t--)
		{
			int s=dirty.top();
			wash.push(s);
			dirty.pop();				
		}
	}
	//dry
	else
	{
		while(t--)
		{
			int s=wash.top();
			dry.push(s);
			wash.pop(); 
		} 
	}
}

int main()
{
	int n;
	cin>>n;
	//�����ӱ�� 
	for(int i=n;i>=1;i--)
	{
		dirty.push(i);
	}
	
	//�������� 
	int op,t;
	while(cin>>op>>t)
	{
		oper(op,t);
	}

	//������ɵ�����
	while(!dry.empty())
	{
		cout<<dry.top()<<endl;
		dry.pop(); 
	} 
	return 0;
}
