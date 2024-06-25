/*
《无敌破坏王2》上映啦！QWQ作为Disney的忠实粉丝当然去贡献票房了。电影里的无敌破坏王和云妮洛普来到了互联网的世界，
在这里，每个上网的人都是一个个虚拟的相同的小人物，当他们点击到某个网站时，虚拟的人物会乘坐一个神奇的传送器前往目的网站。
QWQ看到这个细节认为一个神奇的传送器只搭载一个人传输效率太低了，所以他觉得如果每个传送器能够搭载无数个人就好了，
那么如果此时只有m个神奇的传送器，但有n个人等着被传送，不允许传送器有空载并且每个人看作是相同的，有多少种安排方式呢？
Input
先输入一个t，代表数据的组数
每组数据只有一行有两个数字，之间用一个空格作为间隔，分表代表m、n
保证1<=m<=n<=12
Output
对于每组数据，输出一个数字，代表安排方式的种数
Sample Input
1
1 2
Sample Output
1
*/

#include<bits/stdc++.h>

using namespace std;


int main()
{
	int t;
	cin>>t; 
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		if(m==1)
		{
			cout<<1<<endl;
		} 
		else
		{
			int tran=m;
			int peo=n;
			int n1=peo-1;
			int n2=tran-1;
			int t1=n1;
			int t2=n2;
			for(int j=0;j<n2-1;j++)
			{
				n1=n1*(t1-1);
				t1-=1;
			}
			int cou=n2;
			for(int k=0;k<cou-1;k++)
			{
				n2=n2*(t2-1);
				t2-=1;
			}
			int res=n1/n2;
			cout<<res<<endl;	
		}
	}
	return 0;
}
