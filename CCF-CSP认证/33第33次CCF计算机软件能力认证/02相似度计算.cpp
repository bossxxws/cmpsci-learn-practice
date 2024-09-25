#include<bits/stdc++.h>

using namespace std;

int n,m; 

const int N=1e4;

unordered_set<string>s1,s2;

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		string x;
		cin>>x;
		transform(x.begin(),x.end(),x.begin(),::toupper);

		s1.insert(x);
	}
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		string x;
		cin>>x;
		transform(x.begin(),x.end(),x.begin(),::toupper);

		s2.insert(x);
	}
	
	for(auto t:s1)
	{
		if(s2.find(t)!=s2.end())
		{
			cnt++;
		}
	}
	
	int total=s1.size()+s2.size();
	cout<<cnt<<endl<<total-cnt;
	return 0;
}
