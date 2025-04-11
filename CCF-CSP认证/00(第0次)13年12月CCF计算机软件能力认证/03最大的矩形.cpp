#include<bits/stdc++.h>

using namespace std;

int n;
int h[1010]; 
int maxv=-1;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	
	int l=1;
	for(int i=l;i<=n;i++)//枚举左端点 
	{
		for(int j=1;j+i-1<=n;j++)//枚举区间长度 
		{
			int minh=5e4;
			int r=j+i-1;//得出右端点 
			for(int k=i;k<=r;k++)//枚举这个区间最矮的高度
			{
				if(h[k]<minh)minh=h[k];
			}
			//计算最大面积
			int s=j*minh; 
			//cout<<s<<" "<<j<<" "<<minh<<endl;
			if(s>maxv)maxv=s;
		}
	}
	cout<<maxv;
	return 0;
}
