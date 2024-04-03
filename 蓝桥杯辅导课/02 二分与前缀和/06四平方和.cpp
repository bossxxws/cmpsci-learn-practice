#include<bits/stdc++.h>

using namespace std;

int n; 

const int N=5e6+10;

int r[N*2];

int main()
{
	cin>>n;
	memset(r,-1,sizeof r);
	//a用来记录 a**2 + b**2的和 

	for(int a=0;a*a<=n;a++)
		for(int b=a;b*b+a*a<=n;b++)
		{
			int t=a*a+b*b;
			if(r[t]==-1)r[t]=a*a;//这样可以求出b**2
		}
    bool f=false;

	for(int c=0;c*c<=n;c++)
	{

	    for(int d=c;c*c+d*d<=n;d++)
		{
			int t=n-c*c-d*d;
			if(r[t]==-1)continue;//说明这个方案行不通
			int b=sqrt(t-r[t]);
			int a=sqrt(r[t]);
			cout<<c<<" "<<d<<" "<<a<<" "<<b;
            return 0;
		} 
	    
	}

	return 0;
}
