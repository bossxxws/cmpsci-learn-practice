#include<bits/stdc++.h>

using namespace std;

int T;
int main()
{
	cin>>T;
	while(T--)
	{
		int h1,m1,s1,h2,m2,s2,d=0;
		
		scanf("%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
		int time1=h1*3600+m1*60+s1;
		int time2=d*24*3600+h2*3600+m2*60+s2;
		int t1=time2-time1;
		d=0;
		scanf("%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
		time1=h1*3600+m1*60+s1;
		time2=d*24*3600+h2*3600+m2*60+s2;
		int t2=time2-time1;
		int t=(t1+t2)>>1;
		int h=t/3600;
		int s=t%60;
		int m=((t-3600*h)-s)/60;
		//cout<<h<<m<<s<<endl; 
		printf("%02d:%02d:%02d\n",h,m,s);
	}
	return 0;
} 

/*

3

17:48:19 21:57:24
11:05:18 15:14:23

17:21:07 00:31:46 (+1)
23:02:41 16:13:20 (+1)

10:19:19 20:41:24
22:19:04 16:41:09 (+1)

*/
