#include<bits/stdc++.h>

using namespace std;

vector<int> get_divisors(int x)
{
	vector<int> res;
	
	for(int i=1;i<=x/i;i++)
	{
		if(x%i==0)
		{
			res.push_back(i);
			if(i!=x/i)res.push_back(x/i);//�����һ���ǲ���ͬһ�����������		
		}
	}
	sort(res.begin(),res.end());
	return res;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		
		vector<int> res=get_divisors(x);
		for(auto ele:res)cout<<ele<<" ";
		cout<<endl;		
	}
	return 0;
} 
