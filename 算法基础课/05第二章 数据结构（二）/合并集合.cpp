//���鼯 
/*
1.������Ԫ�غϲ�
2.ѯ������Ԫ���Ƿ���һ�������� 
*/ 
//����ԭ����tree�洢���ϡ������ı�ž����������ϵı��
//         ÿ���ڵ�洢���ĸ��ڵ㣬p[x]x�ı�ʾ���ڵ� 
//����ж����� if p��x��==x
//�����x�ļ��ϱ�� while��p��x����=x��x=p��x��
//��κϲ��������� px��x�ļ��ϱ�ţ�py��y�ļ��ϱ�š�p��x��=y 
//�Ż���
//�ҳ����ڵ㣺��һ������֮��ֱ�ӱ�Ǹ��ڵ㣨·��ѹ����
 
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;
int p[N]; 

int find(int x)  //����x���ڼ��ϵı�� (���ڽڵ�) +·��ѹ�� 
{
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)p[i]=i;
	while(m--)
	{
		char op[2];
		int a,b;
		cin>>op>>a>>b;
		if(op[0]=='M')p[find(a)]=find(b);//�ϲ�
		else 
		{
			if(find(a)==find(b))cout<<"Yes"<<endl;
			else cout<<"No"<<endl; 
		}
	}
	return 0;
}
