#include<bits/stdc++.h>

using namespace std;

priority_queue<int,vector<int>,greater<int>> qmin;
priority_queue<int,vector<int>> qmax;

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		qmin.push(t);
		qmax.push(t);
	}
	long long ans[2];
	int cnt=0;
	int a,b,c,d;
	//����ȥ��С 
	int qma=qmax.top();qmax.pop();
	int qmi=qmin.top();qmin.pop();
	
	int qma1=qmax.top();
	int qmi1=qmin.top();
	
	a=qma-qmi;//������С 
	
	b=qma-qmi1;//������С 
	c=qma1-qmi;//�δ����С 
	
	int t=max(b,c);
	
	cout<<a<<" "<<t;
	return 0;	
} 
