#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;

char a[N];

int f[N];

int main()
{
	scanf("%s",a+1);//从1索引开始读取
	
	int n=strlen(a+1);
	
	for(int i=1;i<=n;i++)
	{
	    //cout<<a[i]<<" ";
		f[i]=a[i]-'a'+1;
	}
	
	//int res=-1;
	
	for(int i=1;i<=n;i++)
	{

		f[i]=max(f[i],f[i-1]);
		if(i-2>=0)f[i]=max(f[i],f[i-2]+(a[i]-'a'+1));
		//cout<<f[i]<<endl;
		//res=max(res,f[i]);还可以再优化！
		
	} 
	
	cout<<f[n];
	return 0;
}
