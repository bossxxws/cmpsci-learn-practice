#include<bits/stdc++.h>

using namespace std;

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isleap(int y)
{
	if((y%100 && y%4==0 )||y%400 )return true;
	return false;
}

bool check(int y,int m,int d)
{
	if(m<=0 || m>12)return false;
	if(d==0)return false;
	if(m==2)
	{
		if(d>days[m]+isleap(y))return false;
	}
	else
	{
		if(d>days[m])return false;
	}
	return true;
}

int d1,d2;

int main()
{
	cin>>d1>>d2;
	int res=0;
	for(int i=d1;i<=d2;i++)
	{
		int y=i/10000;
		int m=i/100%100;
		int d=i%100;
		if(check(y,m,d))
		{
			int t=m*100+d;
			string a=to_string(t);
			//reverse(a.begin(),a.end());
			string aux="";
			for(int i=0;i<a.size();i++)
			{
				aux=a[i]+aux;
			}
			string b=to_string(y);
			if(aux==b)res++;
		}
	}
	cout<<res;
}
