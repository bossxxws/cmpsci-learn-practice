/*
Description
本次ACM校赛得到了海贼科技的小部分奖品的赞助（30个水杯），尽管赞助的奖品不多，但也是要感谢赞助商的！
由于水杯是加急定制的，所以生产水杯的的过程和以往不同，从而导致了水杯的高度竟然是不一样的；
规定水杯高度低于20.00CM 为不合格的产品，你能计算一下这批水杯的合格率吗？
Input
本题单组数据！
输入数据第一行为n，表示水杯的数量；接下来是这n个水杯的高度（实数）；
Output
输出这批水杯的合格率（保留2位小数）；合格率=合格数量/总数
Sample Input
5
19.23 18.00 21.00 22.00 20.00
Sample Output
0.60
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	double good=0;
	int total;
	cin>>total;
	double arr[total];
	for(int i=0;i<total;i++)cin>>arr[i];
	for(int i=0;i<total;i++)
	{
		if(arr[i]>=20.00)
		{
			good++;
		}
	}
	double res=good/total;
	cout<<fixed<<setprecision(2)<<res;
	return 0;
}
