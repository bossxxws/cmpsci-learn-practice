//裴蜀定理
//对于任意正整数a，b，一定存在整数x，y，使得ax+by=（a，b）（最大公约数一般用小括号表示）
// a和b的最大公约数也是a和b能凑出来的最小的正整数




#include<bits/stdc++.h>

using namespace std;

/*

int gcd(int a,int b)
{
	return b?gcd(b,a%b)!a;
} 

*/

int exgcd(int a,int b,int &x,int &y)//ax+by=d
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	
	int d=exgcd(b,a%b,y,x);
	
	//(a,b)=(b,a mod b)
	//by+（a mod b）x = d；
	//a mod b = a - |a/b|*b    （|a/b|表示向下取整）
	
	//保持参数位置中的等式关系：第一个位置*第三个位置加上第二个位置*第四个位置=最大公约数
	//此时的b相当于a，a mod b相当于b
	//y相当于x，x相当于y
	//ax+by=d--->by+(a mod b)x=(a,b)
	
	y=y-a/b*x;
	
	return d;
}


int main()
{
    int n;
    cin>>n;
    
    while(n--)
    {
    	int a,b,x,y;//(x和y初始都是0)
    	cin>>a>>b;
    	
    	exgcd(a,b,x,y);
    	
    	cout<<x<<" "<<y<<endl;
    }
    
    
    return 0;
}
