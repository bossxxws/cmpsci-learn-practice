#include<bits/stdc++.h>

using namespace std;

int n; 

const int N=5e6+10;

int r[N*2];

int main()
{
	cin>>n;
	memset(r,-1,sizeof r);
	//a������¼ a**2 + b**2�ĺ� 

	for(int a=0;a*a<=n;a++)
		for(int b=a;b*b+a*a<=n;b++)
		{
			int t=a*a+b*b;
			if(r[t]==-1)r[t]=a*a;//�����������b**2
		}
    bool f=false;

	for(int c=0;c*c<=n;c++)
	{

	    for(int d=c;c*c+d*d<=n;d++)
		{
			int t=n-c*c-d*d;
			if(r[t]==-1)continue;//˵����������в�ͨ
			int b=sqrt(t-r[t]);
			int a=sqrt(r[t]);
			cout<<c<<" "<<d<<" "<<a<<" "<<b;
            return 0;
		} 
	    
	}

	return 0;
}
