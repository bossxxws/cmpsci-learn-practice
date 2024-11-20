#include<bits/stdc++.h>

using namespace std;

int months[]={0,31,100000,31,30,31,30,31,31,30,31,30,31};

bool isleap(int y)
{
	if((y%100!=0 && y%4==0) || (y%400==0))
	{
		months[2]=29;
		return true;
	}
	else
	{
		months[2]=28;
		return false;
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	int t=isleap(n);
	
	int cnt=1;
	
	int d=-1;
	
	while(m)
	{
		if(m<=months[cnt])
		{
			d=m;
			break;
		}
		else
		{
			m-=months[cnt];
			cnt++;
		}
	}
	cout<<cnt<<endl;;
	cout<<d<<endl;
	
	return 0;
}
