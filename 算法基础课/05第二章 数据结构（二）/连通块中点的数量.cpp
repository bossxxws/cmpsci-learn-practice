#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;
int p[N],siz[N]; 

int find(int x)  //����x���ڼ��ϵı�� (���ڽڵ�) +·��ѹ�� (����Ҫ�ģ�һ��Ҫ��סfind������ 
{
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    p[i]=i;
	    siz[i]=1;//�ʼÿһ������ֻ��һ���㣬size==1
	}
	while(m--)
	{
		char op[5];
		int a,b;
		cin>>op;
		if(op[0]=='C')
		{
		    cin>>a>>b;
		    if (find(a)==find(b)) continue;
		    siz[find(b)]+=siz[find(a)];//���ڵ��size�ϲ���ֻ�и��ڵ��size����Ч�ģ�
		    p[find(a)]=find(b);//�ϲ�
		}
		else if (op[1]=='1')
		{
		    cin>>a>>b;
		    if(find(a)==find(b))cout<<"Yes"<<endl;
			else cout<<"No"<<endl; 
		}
		else 
		{
            cin>>a;
            cout<<siz[find(a)]<<endl;
		}
	}
	return 0;
}
