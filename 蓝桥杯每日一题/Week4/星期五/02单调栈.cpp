#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 +5 ;

int tt;//tt==0µÄÊ±ºòÕ»Îª¿Õ 
int s[N];
 

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
	    int x;
	    cin>>x;
		while(tt>0 && s[tt]>=x)tt--;
		if(tt<=0)cout<<"-1"<<" ";
		else cout<<s[tt]<<" ";
		s[++tt]=x;
	}	
	return 0;
}
