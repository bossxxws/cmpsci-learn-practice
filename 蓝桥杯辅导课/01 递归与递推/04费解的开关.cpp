#include<bits/stdc++.h>

using namespace std;

const int N=6;

//第一行的操作选定后能决定整个图的状态
//最后查看最后一行有没有灭的就知道可不可行 
char a[N][N];

//op代表第一行某个位置操作与否 

int n;

char backup[N][N];

int dx[]={-1,1,0,0,0};
int dy[]={0,0,-1,1,0};

void turn(int x,int y)
{
        for(int i=0;i<5;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if( nx<0 || ny<0 || nx>4 || ny>4 )continue;//不合法行为直接跳过
			
			//字符0的ASCII码是48 -- 110000
			//字符1的ASCII码是49 -- 110001
			//我们要把0变成1，1变成0，那就直接异或就行了（异或是不进位的加法）
			a[nx][ny]^=1;
			//if(a[nx][ny]=='0') a[nx][ny]='1';
			//else if (a[nx][ny]=='1')a[nx][ny]='0';
		}
}

int main()
{
	cin>>n;
	while(n--)
	{
	    //cout<<n;
		for(int i=0;i<5;i++)scanf("%s",a[i]);

		int res=100;

		for(int op=0;op<32;op++)
		{
			int step=0;
			memcpy(backup,a,sizeof a);
			for(int i=0;i<5;i++)
			{
				if(op>>i&1)
				{
					step++;
					turn(0,i);//第i个位置操作一下 
				}
			}
			//第一行的操作枚举完一种了
			//接下来通过上一行的状态来操作下一行 
			for(int i=0;i<4;i++)//看到倒数第二行，操作到倒数第一行 
			{
				for(int j=0;j<5;j++)
				{
					if(a[i][j]=='0')
					{
						step++;
						turn(i+1,j);//把正下方的操作一下（不一定是打开） 以便于让自身打开 
					}
				}
			}

			//判断最后一行有没有暗的
			bool f=true;
			for(int i=0;i<5;i++)
			{
				if(a[4][i]=='0')
				{
					f=false;
					break;	
				}	
			} 
			if(f)
			{
				res=min(res,step);
			}
			memcpy(a,backup,sizeof backup);
			//cout<<step;
		}

		if(res<=6)cout<<res<<endl;
		else cout<<-1<<endl; 

	
	}
	return 0;
}
