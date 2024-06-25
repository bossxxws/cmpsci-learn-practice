/*
Description
QWQ来到了一个神奇的地方，这个地方有很多颜色不同的彩色石，每个颜色都可以用一个数字来代替，QWQ收集了一堆石子，他想知道这堆石子中颜色相同的石子个数的最大值
Input
第1行输入一个数字n，代表这堆石子的个数
第二行输入n个数，代表n个石子的颜色 
保证输入的所有数都不超过100
Output
输出一个数字，代表颜色相同的石子个数的最大值
Sample Input
10
1 3 5 7 9 1 2 3 5 5
Sample Output
3
*/
#include<bits/stdc++.h>

using namespace std;

const int N=1e5;
int ar[N];

int main()
{
	int res=0;
	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)cin>>arr[i];
	
	
	for(int i=0;i<n;i++)
	{
		ar[arr[i]]++;
		if(ar[arr[i]]>res)res=ar[arr[i]];
	}
	cout<<res;
	return 0;
}
