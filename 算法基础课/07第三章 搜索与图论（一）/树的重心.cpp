//dfs依此枚举把每一个点删除之后，剩余另一部分连通块中点的大小
//比较的是剩余的一部分（剩余部分必定连通，是一个连通块，并且不包含删掉的点）
//从中找出最小的连通块大小即可
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10,M=N*2;
int n,m;
int h[N],e[M],ne[M],idx;//邻接表表示法，h[N]存的是多个头 ，单链表内部次序无关紧要
bool st[N];//存储标记遍历过的点 
int ans=N; 

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;//头插法 
}

//树和图的深度优先遍历 
//以u为根的连通块的点的数量 
int dfs(int u)//u表示dfs到的点 
{
	st[u]=true;//已经被搜过了
	int sum=1;
	int res=0;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(!st[j])
		{
			int s=dfs(j);
			res=max(res,s);//以s为根（包含s）的连通块中点的数量
			sum+=s;
		}
	}//这里最终sum为以u为根（包含u）的连通块中点的数量，而u要删掉的，所以不能包含u来选出最大的连通点数量
	
	res=max(res,n-sum);//res是最大连通块包含的点数
	
	ans=min(ans,res);//ans 取出所有方案中最大连通块所含点数中  最小的包含点数
	
	return sum;
}

int main()
{
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);//无向的所以说加两个边
		add(b,a);
		
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
