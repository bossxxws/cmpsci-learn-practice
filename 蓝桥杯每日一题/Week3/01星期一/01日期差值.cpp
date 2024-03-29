#include<bits/stdc++.h>

using namespace std;

int n,m;

const int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int isleap(int y)
{
	if(y%100&&y%4==0 || y%400==0)return 1;
	return 0;
}

int getyear(int y)
{
	int res=0;
	for(int i=1;i<y;i++)
	{
		res+=365+isleap(i);
	}
	return res;
}

int getmonth(int y,int m)
{
	int res=month[m];
	if(m==2)res+=isleap(y);
	return res;
}

int gettotal(int y,int m,int d)
{
	int res=0;
	for(int i=1;i<y;i++)res+=365+isleap(i);
	
	for(int i=1;i<m;i++)res+=getmonth(y,i);
	
	res+=d;
	
	return res;
}

int main()
{
	int y1,m1,d1;
	while(scanf("%04d%02d%02d",&y1,&m1,&d1)!=-1)
	{
		int y2,m2,d2;
		scanf("%04d%02d%02d",&y2,&m2,&d2);
		//取出年份
		//int y1=n/10000;
		//int y2=m/10000;
		
		//int m1=n%10000/100;
		//int m2=m%10000/100; 
		
		//int d1=n%10000%100;
		//int d2=m%10000%100;
		
		//int res=(y2-y1)*365+(m2-m1)*30+(d2-d1);
		
		//cout<<abs(res)+1<<endl;
		
		//cout<<y1<<" "<<m1<<" "<<d1;
		cout<<abs(gettotal(y1,m1,d1)-gettotal(y2,m2,d2))+1<<endl;
	}
	
	
	return 0;
} 
