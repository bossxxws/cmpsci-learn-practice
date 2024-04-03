#include<bits/stdc++.h>

using namespace std;

string a,b; 

int main()
{
	cin>>a>>b;
	//cout<<a<<endl<<b;
	int s=a.size();
	int cnt=0;
	for(int i=0;i<s;i++)
	{
		if(a[i]!=b[i])//如果这个位置上不相同 
		{
			cnt++;
			if(a[i]=='o')a[i]='*';
			else a[i]='o';
			
			if(i+1==s)break;
			if(a[i+1]=='o')a[i+1]='*';
			else a[i+1]='o';
			
		}
	}
	cout<<cnt;
	return 0;
	
}
