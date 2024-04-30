#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int a[N];

int f[N];

//每次都拦截最长下降子序列
//如果拦截完还有，就要把拦截过的去掉
//求的是第一次最多拦截的导弹数
//还有最少需要配备多少个系统才能拦截所有导弹
 
int main()
{
	
	vector<int> a={0};
	//int h=1;
	int t;
	while(cin>>t)
	{
		
		//a[h++]=t;
		a.push_back(t);
	}


	//最长下降子序列	
	for(int i=a.size()-1;i>=0;i--)
	{
		
		f[i]=1;
		
		for(int j=a.size()-1;j>i;j--)
		{
			
			if(a[j]<=a[i])f[i]=max(f[i],f[j]+1);
			
		}
		
	}
	
	int res=-1;
	
	for(int i=1;i<a.size();i++)res=max(res,f[i]);
	
	//cout<<h<<endl;
	////for(int i=1;i<h;i++)cout<<a[i]<<endl;
	cout<<f[6];
	
	return 0;
} 
