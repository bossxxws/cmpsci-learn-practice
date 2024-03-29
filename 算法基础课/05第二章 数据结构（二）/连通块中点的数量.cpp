#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;
int p[N],siz[N]; 

int find(int x)  //返回x所在集合的编号 (祖宗节点) +路径压缩 (最重要的，一定要记住find函数） 
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
	    siz[i]=1;//最开始每一个集合只有一个点，size==1
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
		    siz[find(b)]+=siz[find(a)];//根节点的size合并（只有根节点的size是有效的）
		    p[find(a)]=find(b);//合并
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
