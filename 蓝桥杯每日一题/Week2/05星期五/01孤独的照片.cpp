#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int n; 

const int N=5e5+3;

char a[N];


int l[N],r[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%s",&a[i]);//G H
	//for(int i=1;i<=n;i++)printf("%c\n",a[i]);//G H
	
	LL res=0;
	
	for(int i=1,sh=0,sg=0;i<=n;i++)
	{
		if(a[i]=='G')l[i]=sh,sh=0,sg++;
		else  l[i]=sg,sg=0,sh++;
	}//记录某一个位置左边连续的不同的牛的数量 
	
	for(int i=n,sh=0,sg=0;i>=1;i--)
	{
		if(a[i]=='G')r[i]=sh,sh=0,sg++;
		else  r[i]=sg,sg=0,sh++;
	}//记录某一个位置右边连续的不同的牛的数量

	for(int i=1;i<=n;i++)
	{
		if(l[i]&&r[i])res+=(LL)l[i]*r[i];
		res+=(LL)max(r[i]-1,0);
		res+=(LL)max(l[i]-1,0); 
	}

    cout<<res;
	
	return 0;
} 
