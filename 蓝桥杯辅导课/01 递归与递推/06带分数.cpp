#include<bits/stdc++.h>

using namespace std;

const int N=600;

int n;

int ans;

int had_use[N];

int toolmap[N];

bool check(int a,int c)
{
	int b=n*c-a*c;
	
	memcpy(toolmap,had_use,sizeof toolmap);
	
	if(!a || !b || !c)return false;//������0 
	
	while(b)
	{
		int t=b%10;

		if(!t || toolmap[t])return false;//!t�����0��toolmap�����ظ� 
		
		toolmap[t]=1;
		b/=10;
	}
	
	for(int i=1;i<=9;i++)if(!toolmap[i])return false;
	
	return true;
}

void dfs_c(int x,int a,int c)//����a�������c���������Ƿ�ϸ� 
{
	if(x>=10)return ;//�����Ÿ����֣����Ϸ�����֦
	
	if(check(a,c))ans++;//���Ŀǰ��a��c�Ƿ�ϸ� 
	
	//ö�� c 
	for(int i=1;i<=9;i++)
	{
		if(!had_use[i])
		{
			had_use[i]=1;
			dfs_c(x,a,c*10+i);
			had_use[i]=0;
		}
	}
	 
}

void dfs_a(int x,int a)//x��ʾ�õ����ĸ��� 
{
	if(a>=n)return ;//����n�� a û������ ����֦ 
	
	if(x>=10)return ;//�õ����ֳ���9���򲻺Ϸ�����֦ 
	
	if(a)dfs_c(x,a,0);//ѡ��a֮��ʼö��c 
	
	for(int i=1;i<=9;i++)//a���λ��ȡĳ���� 
	{
		if(!had_use[i])
		{
			had_use[i]=1;//���Ϊ�ù� 
			dfs_a(x+1,a*10+i);//����ݹ� 
			had_use[i]=0;//�ָ��ֳ� 
		}
	}
}

int main()
{
	cin>>n;
	
	//n=a+b/c
	//cn=ac+b
	//b=cn-ac�������������b��ֻ��ö��c 
	
	dfs_a(0,0);
	cout<<ans;
	return 0;
}
