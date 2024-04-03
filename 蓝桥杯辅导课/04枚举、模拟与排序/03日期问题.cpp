#include<bits/stdc++.h>

using namespace std;

int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int isleap(int y)
{
	if((y%100 && y%4==0) || y%400==0)return 1;
	else return 0;
}

bool check(int year,int month,int day)
{
	if(month<=0 || month>12)return false;
	if(day==0)return false;
    if(month!=2)
    {
        if (day > months[month]) return false;
    }
    else
    {
        if(day>months[month]+isleap(year))return false;
    }
	return true;
}

int main()
{
	//年月日
	//月日年 
	//日月年 
	int a,b,c;
	scanf("%d/%d/%d",&a,&b,&c);
	
	for(int i=19600101;i<=20591231;i++)
	{
		int y=i/10000,m=i%10000/100,d=i%100;

		if(check(y,m,d))
		{
			if((y%100==a && m==b && d==c) ||
			  (m==a && d==b && y%100==c)||
			  (d==a && m==b && y%100==c))
			  {
			  	printf("%d-%02d-%02d\n",y,m,d);
			  }
		}
	} 
	return 0;
}
