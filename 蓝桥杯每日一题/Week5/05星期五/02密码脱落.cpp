#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5;

int n;

char a[N];

int f[N][N];//以i、j为两端的区间中的最长回文字符串长度 

int main()
{

	scanf("%s",a+1);

	
	int n=strlen(a+1);
	
	//cout<<n<<endl;
	
	for(int len=1;len<=n;len++)//枚举区间长度 
		for(int l=1;l+len-1<=n;l++)//枚举左端点
		{
			int r=l+len-1;
			if(len==1)f[l][r]=1;//本身就是一个回文字符串
			else
			{
				f[l][r]=max(f[l+1][r],f[l][r-1]);
			
				if(a[l]==a[r])f[l][r]=max(f[l][r],f[l+1][r-1]+2);
			}

		} 
	
	cout<<n-f[1][n]<<endl;
	
	return 0;
} 
