#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=505;

//前缀和 
int s[N][N];

int main()
{
    ios::sync_with_stdio(false);//没这个不行，或者用scanf
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
		
	
			
	LL res=0;
	
	for(int i=1;i<=m;i++)//l i -> f j
		for(int j=i;j<=m;j++)//s维护上界，f维护下界 ，注意j=i！！！！！！
			for(int l=1,f=1;f<=n;f++)
			{
				while(l<=f && s[f][j]-s[l-1][j]-s[f][i-1]+s[l-1][i-1]>k)l++;
				if(l<=f)res+=f-l+1;
			}
	cout<<res;
	return 0;
} 
