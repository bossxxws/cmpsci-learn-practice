#include<bits/stdc++.h>

using namespace std;

const int N=4e4+9;//��Ϊ��άת��Ϊһά�ˣ�����һά�ռ���뿪N��ƽ���� ��200*200�� 
int p[N];

int find(int x)
{
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}

void merge(int a,int b)
{
	p[find(a)]=find(b);
}

int main()
{
	int n,m;
	
	cin>>n>>m;
	for(int i=1;i<=n*n;i++)p[i]=i;
	
	int cnt=1;
    for(int i=1;i<=m;i++)
    {
    	int a,b;
    	char c;
    	cin>>a>>b>>c;
    	
    	int p=(a-1)*n+b;//p��ʾԭ�������� 
    	
    	int q;//q��ʾ��һ�ˣ����»������ң� 
    	if(c=='D')q=a*n+b;
    	else q=(a-1)*n+b+1;
    	
    
    	//cout<<find(p)<<" "<<find(q)<<endl;
    	if(find(p)==find(q))
    	{
    		cout<<i;
    		return 0;
    	}
    	merge(p,q);
	}
	cout<<"draw";
	return 0;
}
