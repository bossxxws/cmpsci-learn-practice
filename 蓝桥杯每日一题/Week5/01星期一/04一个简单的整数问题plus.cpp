#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int a[N];
int tr[N];

int n,m;

int lowbit(int x)
{
	return x&-x;
}


int query(int x)
{
    //��״���������ͺ���ĳһ��λ�õı仯ֵ������������һ���������ֵ��������ı仯ֵ
	int res=0;
	for(int i=x;i;i-=lowbit(i))
	//ע����i>0��ǧ��Ҫдi>=0,��Ϊi���պ�Ϊ0���߶����Ǵ�1��ʼ�ģ� 
	//i��ȥ�Լ��ĵ�λ1����С��0���ظ���ȥ�Լ��ĵ�λi�����һ�������0�� 
	{
		res+=tr[i];
	}
	return a[x]+res;
}

void add(int pos,int v)
{
	for(int i=pos;i<=n;i+=lowbit(i))
	{
		tr[i]+=v;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	//cout<<1;
	while(m--)
	{
		char op[2];
		//cout<<1;
		scanf("%s",op);
		//cout<<2;
		if(op[0]=='C')
		{
			//cout<<1;
			int l,r,c;
			cin>>l>>r>>c;
			add(l,c);add(r+1,-c);//��״��������״������� 
		}
		else
		{
			//cout<<2;
			int x;
			scanf("%d",&x);
			//cout<<1;
			cout<<query(x)<<endl;
		}
	}
	return 0;
}
