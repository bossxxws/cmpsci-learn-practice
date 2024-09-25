#include<bits/stdc++.h>

using namespace std;

int n,m; 

const int N= 103;

//统计所有文章总共包含几个i，并且包含i的文章的个数 

int a[N][N];
int lth[N];//记录长度数组 
int ma[N];
int cnt,mark;

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		cin>>lth[i];
		for(int j=1;j<=lth[i];j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	//开始统计个数,从单词编号入手 
	for(int i=1;i<=m;i++)
	{
		cnt=0;
		bool flag=false;
		mark=0;
		for(int j=1;j<=n;j++)//枚举每一个数组 
		{
			for(int k=1;k<=lth[j];k++)//枚举到每一个序列的最后一个 
			{
				if(a[j][k]==i)
				{
				    cnt++;
    				flag=true;
				}

			}
			if(flag)
			{
				mark++;//记录出现此数的文章的篇数
				flag=false;
			}	 
		}
		cout<<mark<<" "<<cnt<<endl;
	} 

	return 0;
} 
