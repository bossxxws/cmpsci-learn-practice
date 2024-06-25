/*
Description
    太极生两仪,两仪生四象,四象生八卦,八卦生万物。天地初开，万物皆欲成双成对；芸芸丛生，谁愿孤苦伶仃。知音难觅，阳春白雪绕梁何久，千古一绝，神雕侠女驰骋九洲。
天下岂无双？千古绝唱为知音。情寄雨丝丝，述相思之意；梦随风万里，寻同道之人。共聚一堂，为梦想而努力；携手共进，为程序而疯狂！
夜夜编程不漫长，只因与君共拼搏……
给定n个数，其数值范围在1到n-1中，已知其中必有两个数是相同的，要求你找出并输出。（2<=n<=1，000,000）
Input
多组数据输入.
每组输入第一行一个数n。第二行n个数，其数值范围为1..n-1。
Output
每组输出一行一个数，即出现过两次的数。
Sample Input
5
2 3 1 4 2
8
7 6 1 2 3 5 4 7
Sample Output
2
7
*/
#include<bits/stdc++.h>

using namespace std;

const int N=1e6;

int ar[N],arr[N];

int main()
{
	int n;
	while(cin>>n)
	{
		memset(ar,0,sizeof(ar));
		memset(arr,0,sizeof(ar)); 
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
			if(arr[ar[i]])
			{
				cout<<ar[i]<<"\n";
			}
			else arr[ar[i]]=1;			
		}	
	}
	return 0;
}
