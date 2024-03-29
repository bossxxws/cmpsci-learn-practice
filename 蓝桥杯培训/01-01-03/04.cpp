/*
众所周知QWQ的棋艺已经到了独孤求败的地步，某日一位来自泰坦星的勇士前来向QWQ发起挑战，不过挑战的项目却非常奇怪：
这位勇士要求QWQ在一个n x n大小的棋盘上放置k个棋子，并要求放置后的棋盘上每一行和每一列最多有一个棋子，显然这个问题是如此的简单，
所以这位勇士要求QWQ告诉他这样的棋局共有多少种？
你能帮助QWQ解决这个问题么？
Input
每组输入占据一行
一行有两个数字 分别表示棋盘的大小n和要求放置的棋子k
0<n<9 , 0<k<=n
Output
每组输入占据一行
输出这样的棋局的种类数目
Sample Input
样例一：
2 1

样例二：
2 2
Sample Output
样例一：
4

样例二：
2
*/

#include<bits/stdc++.h> 

using namespace std;

void putpos(int r,int c)
{
	
}

int main()
{
	int n,k;
	cin>>n>>k;
	//bulid a nxn's qipan ,initial value is 0
	int s[n][n];
	//once decide a pos,del c and r
	int solution=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int tmp=k;
			if(s[i][j]==0)
			{
				s[i][j]=1;
				s[i][n]=1;
				s[n][j]=1;
				tmp--;
				while(tmp)
				{
						
				}
			}
		}
	}
	return 0;
}

