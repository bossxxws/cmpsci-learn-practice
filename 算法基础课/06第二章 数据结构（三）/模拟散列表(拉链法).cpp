//���1e5֮���һ������,�õ�100003 
/*
for(int i=1e5;;i++)
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
#include<bits/stdc++.h>

using namespace std;

const int N=100003;

int h[N],e[N],ne[N],idx;

void insert(int x)
{
	int k=(x%N+N)%N;//��ֱ��x+N��������Ϊ�ᳬ��int���ݷ�(��ֹ��int) 
	e[idx]=x;
	ne[idx]=h[k];
	h[k]=idx++;
}

bool find(int x)
{
	int k=(x%N+N)%N;
	for(int i=h[k];i!=-1;i=ne[i])
	{
		if(e[i]==x)
		{
			return true;
		}
		else return false;
	}
}

int main()
{
	int n;
	cin>>n;
	
	memset(h,-1,sizeof h);
	
	while(n--)
	{
		char op[2];
		int x;
		cin>>op>>x;
		if(op[0]=='I')insert(x);
		else 
		{
			if(find(x))cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		
	}

	return 0;
} 
