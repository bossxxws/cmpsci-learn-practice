#include<bits/stdc++.h>

using namespace std;

const int N=10001;

int a[N];

bool f[N][N];//表示前用i个数能不能凑出j这个数

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;//<pression1>?<pression2>?<pression3>
	//1为真则执行2，1为假则执行3 
}

int main()
{
	int n;
	cin>>n;
	int d;
	//他们的最大公约数不是1的话则有正无穷个无法凑出的数 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d=gcd(d,a[i]);//求这些数的最大公约数 
	}
	
	//两个数的话，如果这两个数的最大公约数是1，他们不能凑出来的
	//最大的数是：（a-1）（b-1）-1
	
	//如果是n个数的话： 
	//设想：如果用两个数，不能凑出来的最大的数就是 （a-1）（b-1）-1
	//如果是n个数，那肯定最大的不能凑出来的数肯定比 （a-1）（b-1）-1小
	
	//所以枚举装台的时候我们就用这个最大的数来枚举一遍（反正a和b最大为100）
	//我们就枚举到10000 
	
	f[0][0]=1;
	
	if(d!=1)
	{
		cout<<"INF"<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=0;j<N;j++)
			{
				f[i][j]=f[i-1][j];
				if(a[i]<=j)f[i][j]|=f[i][j-a[i]];
			}
		
		int res=0;
		
		for(int i=0;i<N;i++)
		{
			if(!f[n][i])res++;
		}
		cout<<res<<endl;
	}

	return 0;
} 
