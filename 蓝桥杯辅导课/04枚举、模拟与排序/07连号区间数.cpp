#include<bits/stdc++.h>

using namespace std;

const int N=1e4+5;

int n; 

int a[N];


int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	
	int res=0;

	for(int i=1;i<=n;i++)
	{
	    int max1=-1;
		int min1=10001;
		for(int j=i;j<=n;j++)
		{

			//���������� 
			max1=max(max1,a[j]);//ά�����ֵ 
			min1=min(min1,a[j]);//ά����Сֵ
			//cout<<max1<<" "<<min1<<endl;
			if((max1-min1)==(j-i))res++; 
			
		}
	}

	cout<<res;
	return 0;
}
