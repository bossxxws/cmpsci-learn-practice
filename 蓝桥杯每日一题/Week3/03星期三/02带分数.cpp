#include<bits/stdc++.h>

using namespace std;

const int N=600;

//typedef long long LL;

int ever[N],had_use[N];
//������������棬acwingƽ̨���ڷ�����ans���浼������������ 

int ans=0;

int  n;


//n=a+b/c
//nc=ac+b
//b=nc-ac ֻҪ�Ƴ�����b����������a��c�������������+1 
bool check(int a,int c)
{
	int b=n*c-a*c;
	
	if(!a || !c || !b)return false;
	
	memcpy(ever,had_use,sizeof had_use);//�������е�����£����ƻ�ԭ��������
	//�ǾͿ���һ�ݣ�������ԭ��֮�ϲ��������ܲ��ƻ�ԭ���ļ�¼ 
	
	while(b)//ȡ��ÿһλ�����������ù������� 
	{
		int t=b%10;
		b/=10;
		if(!t || ever[t])return false;
		ever[t]=1;
	}
	
	for(int i=1;i<=9;i++)if(!ever[i])return false;
	
	return true;
}

void dfs_c(int x,int a,int c)
{
	if(x>=10)return ;
	if(check(a,c))ans++;
	for(int i=1;i<=9;i++)
	{
		if(!had_use[i])
		{
			had_use[i]=1;
			dfs_c(x+1,a,c*10+i);
			had_use[i]=0;//���ݣ������´εĵݹ��г��ִ��� 
		}
	}
}

void dfs_a(int x,int a)
{
	if(a>=n)return;
	if(a)dfs_c(x,a,0);//���a������������ôö��cȻ���ж��Ƿ��ǳ�����
	//0��c�Ĵ�С 
	for(int i=1;i<=9;i++)//ö��һ�µ�ǰ������Щ����
	{
		if(!had_use[i])
		{
			had_use[i]=1;
			dfs_a(x+1,a*10+i);
			had_use[i]=0;//�ָ��ֳ�������һ�� 
		}	
	} 
}

int main()
{	
	//cout<<714*97;
	cin>>n;
	dfs_a(0,0);//��һ����ʾ��ǰ���˶��ٸ����֣��ڶ���������ʾ��ǰ��a�Ƕ��� 
	cout<<ans;
	return 0;
}
