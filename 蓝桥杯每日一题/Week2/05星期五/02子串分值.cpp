#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

typedef long long LL;

int n;
int l[N],r[N],p[26];

char s[N];

int main()
{
	scanf("%s",s+1);
	
	int n=strlen(s+1);
	//���ַ�x���û���ظ���x��ʱ���൱����0���λ����һ��x���ַ������±��1��ʼ��
	//����ʡ������Ϊ0�Ĳ��裺for(int i=0;i<26;i++)p[i]=0;
	//��Ϊ�����ʼ��������0 
	for(int i=1;i<=n;i++)
	{
		int t=s[i]-'a';
		l[i]=p[t];
		p[t]=i;
	}
	
	for(int i=0;i<26;i++)p[i]=n+1;
	//ÿ���ַ����ұ���һ����һ�γ����±��ʼֵ��Ϊn+1 
	//��Ϊ���ַ�y�ұ�û���ظ���y��ʱ���൱����n+1���λ����һ��y���ַ������һ���±�Ϊn�� 
	for(int i=n;i>=1;i--)
	{
		int t=s[i]-'a';
		r[i]=p[t];
		p[t]=i;
	}
	LL res=0;
	for(int i=1;i<=n;i++)
	{
		res+=(LL)(i-l[i])*(r[i]-i);
	}
	cout<<res; 
	return 0;
} 
