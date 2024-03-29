//时间复杂度：O（sqrt（n）） 

#include<bits/stdc++.h>

using namespace std;

void divide(int n)
{
	for(int i=2;i<=n/i;i++)
	{
		if(n%i==0)
		{
			int s=0;
			while(n%i==0)
			{
				n/=i;
				s++;//除i的次数，所以s*i==n
			}
			cout<<i<<" "<<s<<endl;
		}
	}
	if (n>1)cout<<n<<" "<<1<<endl;//除完之后还是大于1，说明n本身是个质因子，直接和1一起输出
	puts("");
}

int main()
{
	
	int n;
	cin>>n;
	while(n--)
	{
	    int a;
	    cin>>a;
	    divide(a);
	}
	return 0;
}
