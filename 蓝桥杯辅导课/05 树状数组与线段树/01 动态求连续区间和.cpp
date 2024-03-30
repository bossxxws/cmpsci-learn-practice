//��״���������е���������ԭ������� 

#include<bits/stdc++.h>

using namespace std;

const int Max=1e6+10;

const int N=1e6+10;

int tree[Max];

//��״������Խ���� 
//ĳ��λ���ϵ���������һ����---�����޸�
//��ĳһ��ǰ׺��---�����ѯ 

//+���=�����޸� �����ѯ || �����޸� �����ѯ 

//ǰ׺�����鲻֧���޸ģ�ֻ֧�ֲ�ѯ 
//lowbit��x��=2**k��kΪĩβ����0�ĸ����� 

// ��״����ÿ��λ�ô�Ķ���ԭ����һ�����ĺ�(��x-lowbit(x)��x)
//c[x]=value[x-lowbit(x) ,x]     

//��״������������� 
int lowbit(int x)
{
	return x&-x;
}

int query(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	{
		res+=tree[i];
	}
	return res;
}

int add(int x,int v)//��ĳһ��λ��x����v ����Ӱ�쵽���������������������д���� 
{
	for(int i=x;i<=Max;i+=lowbit(i))
	{
		tree[i]+=v;
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		add(i,v);
	}

	while(m--)
	{
		int op,a,b;
		scanf("%d%d%d",&op,&a,&b);
		
		if(op==0)
		{
			int res=query(b)-query(a-1);
			printf("%d\n",res);
		}
		else
		{
			add(a,b);
		}
	}
	return 0;
} 
