/*
ά��һ���ַ������ϣ�֧�����ֲ�����

I x �򼯺��в���һ���ַ��� x
��
Q x ѯ��һ���ַ����ڼ����г����˶��ٴΡ�
���� N������������������ַ����ܳ��Ȳ����� 1e5
���ַ���������СдӢ����ĸ��

�����ʽ
��һ�а������� N
����ʾ��������

������ N
 �У�ÿ�а���һ������ָ�ָ��Ϊ I x �� Q x �е�һ�֡�

�����ʽ
����ÿ��ѯ��ָ�� Q x����Ҫ���һ��������Ϊ�������ʾ x
 �ڼ����г��ֵĴ�����

ÿ�����ռһ�С�

���ݷ�Χ
1��N��2?104
����������
5
I abc
Q abc
Q ab
I ab
Q ab
���������
1
0
1
*/

#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

char str[N];

int son[N][26],cnt[N],idx;//�±���0�ĵ㣬���Ǹ��ڵ㣬���ǿսڵ�
//idxΪÿһ���ڵ����Ψһ�ı�ʶ�� 



void insert(char str[])
{
	int p=0;
	for(int i=0;str[i];i++)
	{
		int u=str[i]-'a';
		if(!son[p][u]) son[p][u]= ++ idx;
		p=son[p][u];
	}
	cnt[p]++;
} 

int query(char str[])
{
	int p=0;
	for(int i=0;str[i];i++)
	{
		int u=str[i]-'a';
		if(!son[p][u])return 0;
		p=son[p][u];
	}
	return cnt[p];
}


int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		char op[2];
		cin>>op>>str;
		if(op[0]=='I')insert(str);
		else cout<<query(str)<<endl;
    }
	return 0;
}
