//十万组询问 1<=a<=b<=2000 使用递推 

//cab=a！/（b！*（a-b）！）
//但通过这个一个一个求，每次都要运算一遍时间复杂度很高（十万次询问） 
//所以提前算好所有的，省的面对十万次询问每次都一遍一遍算 

//通过递推式： 
//Cab=C(a-1)b+C(a-1)(b-1)
//初始化s一个数组储存所有Cab的情况，减少时间复杂度 

//时间复杂度：N**2 
#include<bits/stdc++.h>

using namespace std;

const int N = 2010,mod=1e9+7;

int c[N][N];

void init()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			if(!j)c[i][j]=1;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			//i-1已经被全部初始化过所以说可以用来更新 
}

int main()
{
	init();
	
	int n;
	cin>>n;
	
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		cout<<c[a][b]<<endl;
	}
	
	
	return 0;
}
