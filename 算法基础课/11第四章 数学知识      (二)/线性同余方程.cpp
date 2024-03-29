//对于ax mod m 同余 b ，求 x  
//相当于ax=my＋ｂ求x （y是m的倍数） 
//也就是ax - my =b 
//因为y是整数 
//令 y'=y
//也就是ax + my' =b，求出一个x让等式成立
//也就是扩展欧几里得，b是最大公约数。
//要让等式有解， 
//因为a是最大公约数的倍数，m也是最大公约数的倍数，所以ax+my'也是最大公约数的倍数
//b 是最大公约数的倍数 ,则一定有解 
//所以有解的充分必要条件：（ax+my'）b能整除（a，m）      
//(ａ,ｍ)｜ｂ 
//最后因为扩展欧几里得算法求的是ax + my' =d 
//题意是 等式右边为b （b是题目给定，所以b需要是d的倍数才能有答案） 
//第一个式子等式两边同时乘上（b/d） ，得出符合题意的式子 
//求出来的x需要乘上（b/d）,并且要mod m 
//最后别忘了加LL ，并且x应该在m的范围内（因为ax mod m，x必须在m的范围内） 
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int exgcd(int a,int b,int &x,int &y)
{
	if(!b)//b为0时,ax+by只剩a，这时候d=a，等式ax=a，则x=1 
	{
		x=1,y=0;
		return a; 
	}
	int d=exgcd(b,a%b,y,x);
	
	y=y-a/b*x;
	
	return d;
	
}
	

int main()
{
	int n;
	cin>>n;
	

	while(n--)
	{
		int a,b,m;
		cin>>a>>b>>m;
		
		int x,y;
		
		int d=exgcd(a,m,x,y);
		if(b%d)cout<<"impossible"<<endl;
		else cout<<(LL) x * (b/d) % m<<endl;//b能整除d（a和m的最大公约数）才有答案
	}
	
	
	
	return 0;
}
