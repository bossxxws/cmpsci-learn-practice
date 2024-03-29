#include<bits/stdc++.h>

using namespace std;

int n;

typedef pair<int,int> PII;

typedef pair<double,PII> PDP;

const int N=1e5;

vector<PDP>res;

unordered_set<double>cnt;

void work(int n)
{
    
	if(n==0)return ;
	work(n-1);
	for(int i=n-1;i>0;i--)
	{
		double number=(double)i/n;
		if(cnt.find(number)!=cnt.end())continue;
		cnt.insert(number);
		PII t={i,n};
		res.push_back({number,t});
	}
	
}

bool cmp(PDP a,PDP b)
{
    return a.first<b.first;
}

int main()
{
	cin>>n;
	
	res.push_back({0,{0,1}});
	res.push_back({1,{1,1}});
	
	work(n);
    
	sort(res.begin(),res.end(),cmp);

	for(auto t:res)
	{
		cout<<t.second.first<<"/"<<t.second.second<<endl;
	}
	
	return 0;
} 
