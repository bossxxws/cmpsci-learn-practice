//ʱ�临�Ӷȣ�O��sqrt��n���� 

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
				s++;//��i�Ĵ���������s*i==n
			}
			cout<<i<<" "<<s<<endl;
		}
	}
	if (n>1)cout<<n<<" "<<1<<endl;//����֮���Ǵ���1��˵��n�����Ǹ������ӣ�ֱ�Ӻ�1һ�����
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
