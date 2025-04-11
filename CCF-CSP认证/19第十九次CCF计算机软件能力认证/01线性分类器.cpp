#include<bits/stdc++.h>

using namespace std;

const int N=1e3+3;

const int M=23;

typedef long long LL;

struct lne
{
	int th0;
	int th1;
	int th2;
}lne[N]; 

struct idx
{
	int x;
	int y;
	char t;
}d[N];

int n,m; 

LL calcu(int x,int y,int t0,int t1,int t2)
{
//	cout<<"cc "<<x<<" "<<y<<" "<<t0<<" "<<t1<<" "<<t2<<endl;
//	cout<<"cal: "<<t0+t1*x+t2*y<<endl;
    LL res=(LL)t0+(LL)t1*x+(LL)t2*y;
	return res;
}
int main()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>d[i].x>>d[i].y>>d[i].t;
//		cout<<d[i].x<<d[i].y<<d[i].t<<endl;
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>lne[i].th0>>lne[i].th1>>lne[i].th2;
//		cout<<lne[i].th0<<lne[i].th1<<lne[i].th2<<endl;
	}
	
	for(int i=1;i<=m;i++)
	{
		bool f=true;
		bool SA0=false,SA1=false,SB0=false,SB1=false;
		for(int j=1;j<=n;j++)
		{
			LL r=calcu(d[j].x,d[j].y,lne[i].th0,lne[i].th1,lne[i].th2);
//			cout<<"l : "<<lne[i].th0<<" "<<lne[i].th1<<" "<<lne[i].th2<<" "<<endl;
//			cout<<"point : "<<d[j].x<<" "<<d[j].y<<" "<<d[j].t<<" "<<endl;
//			cout<<"r: "<<r<<endl;
//cout<<r<<endl;
			if(r<0 && d[j].t=='A')
			{
//				cout<<r<<endl;
				if(SA1==true || SB0==true)
				{
					f=false;
					break;
				}
				SA0=true;
			}
			else if(r>0 && d[j].t=='A')
			{
//				cout<<"kkkk"<<endl;
				if(SA0==true || SB1==true)
				{
					f=false;
					break;
				}
				SA1=true;
			}
			else if(r<0 && d[j].t=='B')
			{
				if(SB1==true || SA0==true)
				{
					f=false;
					break;
				}
				SB0=true;
			}
			else if(r>0 && d[j].t=='B')
			{
				if(SB0==true || SA1==true)
				{
					f=false;
					break;
				}
				SB1=true;
			}
		}
		if(f)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
// 		cout<<calcu(1000000,1000000,1000000,1000000,1000000)<<endl;
	}
	return 0;
} 
