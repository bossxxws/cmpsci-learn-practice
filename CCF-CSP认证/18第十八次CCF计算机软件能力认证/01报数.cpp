#include<bits/stdc++.h>

using namespace std;

int n; 
int cnt[5];

int check(int x)
{
	return (x%7==0 || x%10==7 || x/10%10==7 || x/100%10==7 || x%1000==7);
}
int cer=0;
int main()
{
	cin>>n;//报出n个数游戏结束
	
	for(int i=0,j=1;cer<n;i++,j++)
	{
		if(!check(j))//不跳过 
		{
			
			cer++;
			
		}
		else
		{
			cnt[i%4]++;
		}
	}
	
	for(int i=0;i<4;i++)
	{
		cout<<cnt[i]<<endl;
	}
	return 0;
} 
