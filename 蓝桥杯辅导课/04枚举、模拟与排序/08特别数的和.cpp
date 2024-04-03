#include<bits/stdc++.h>

using namespace std;

int n; 
int res;
int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int k=i;
		while(k)
		{
			
			int t =k%10;
			if(t==2 || t==0 || t==1 || t==9) 
			{
				res+=i;
				break;
			}
			k/=10;		
		}
	}
	cout<<res;
	return 0;
}
