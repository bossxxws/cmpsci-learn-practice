//1e9+7这是一个质数
#include<bits/stdc++.h>

using namespace std;

//开放寻址发一般开成两倍
//找出200000之后第一个质数
/*
for(int i=2*1e5;;i++)
{
	bool flag=true;
	for(int j=2;j*j<=i;j++)
	{
		if(i%j==0)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<i;
		break;
	}
}
*/ 

const int N=200003,null=0x3f3f3f3f;
//一般设最大值都是0x3f3f3f3f,大约比1e9大一些 
//用null这个数表示位置上没有数字，null这个数字在题目给的数字范围之外，所以说不会引起错误
//如果设置的数在数字范围之内，可能会造成错误判断（本来没有这个数结果每个空位置都是这个数） 
int h[N];

int find(int x)
{
	int k=(x%N+N)%N;
	while(h[k]!=null && h[k]!=x)
	{
		k++;
		if(k==N)k=0;//后面都没有就从头开始找
	}	
	return k;
}

void insert(int x)
{
    int t=find(x);
	h[t]=x;
}

int main()
{
	int n;
	cin>>n;
	
	memset(h,0x3f,sizeof h);//memset是按照字节来set的，
	                        //比如说int是四个字节，则每个字节都是0x3f，即为0x3f3f3f3f
	
	while(n--)
	{
		char op[2];
		int x;
		cin>>op;
		cin>>x;
		if(*op=='I')
		{
			insert(x);
		}
		else
		{
			int k=find(x);
			if(h[k]!=null) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	
	return 0;
}
