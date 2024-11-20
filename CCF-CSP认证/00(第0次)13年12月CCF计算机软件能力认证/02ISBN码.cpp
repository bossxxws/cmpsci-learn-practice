#include<bits/stdc++.h>

using namespace std;

int v[11];
char value;

int a,b,c;

typedef long long LL;

LL k;

int main()
{
	scanf("%d-%d-%d-%c",&a,&b,&c,&value);;
	v[1]=a;
	for(int i=4;i>=2;i--)
	{
		v[i]=b%10;
		b/=10;
	}
// 	cout<<c<<endl;
	for(int i=9;i>=5;i--)
	{
		v[i]=c%10;
		c/=10;
	}
// 	for(int i=1;i<=9;i++)
// 	{
// 		cout<<v[i]<<" ";
// 	}
// 	cout<<endl;
	for(int i=1;i<=9;i++)
	{
		k+=v[i]*i;
	}
	k=k%11;
// 	cout<<k<<endl;
	if(k==10)
	{
		if(value=='X')cout<<"Right";
		else
		{
		    printf("%d-%d%d%d-%d%d%d%d%d-X",v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9]);
		}
	}
	else 
	{
		if(k==(value-'0'))cout<<"Right";
		else
		{
			printf("%d-%d%d%d-%d%d%d%d%d-%d",v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8],v[9],k);
// 			cout<<endl<<v[8]<<endl;
		}
	}
	
	return 0;
} 
