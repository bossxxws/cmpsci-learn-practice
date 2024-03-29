//1960 1 1 --- 2059-12-31
#include<bits/stdc++.h>

using namespace std;

const int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int isleap(int y)
{
	if(y%100&&y%4==0 || y%400==0)return 1;
	return 0;
}

int check(int y,int m,int d)
{
	if(m<0 || m>12)return 0;
	if(d==0)return 0;
	if(d>month[m])
	{
		if(m==2 && d<=(month[m]+isleap(y)))return 1;
		else return 0;
	}
	return 1;
}

int y,m,d;

int main()
{
	scanf("%d/%d/%d",&y,&m,&d);
	
	for(int i=19600101;i<=20591213;i++)
	{
		int yi=i/10000,mi=i%10000/100,di=i%10000%100;
		
		if(check(yi,mi,di))
		{
			if((yi%100==y && mi==m && di==d)  || //年月日 
			(mi==y && di==m && yi%100==d)  || //月日年 
			(di==y  && mi==m && yi%100==d))//日月年 
			{
				printf("%d-%02d-%02d\n",yi,mi,di);
				//cout<<1;
			}
		}
	}	
	return 0;
}
