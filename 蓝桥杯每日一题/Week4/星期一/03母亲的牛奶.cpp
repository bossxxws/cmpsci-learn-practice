#include<bits/stdc++.h>

using namespace std;

const int N=25;

int A,B,C;//容量 

int cc=C,ca=0,cb=0;//c桶7装满了奶，而a桶和b桶是空的


bool vis[N][N][N];

int hh,tt;
struct node 
{
	int a,b,c;
}q[N*N*N];

void insert(int a,int b,int c)
{
	if(!vis[a][b][c])
	{
		q[++tt]={a,b,c};
		vis[a][b][c]=true;	
	}
}

void bfs()
{
	q[0]={0,0,C};
	vis[0][0][C]=true;
	while(hh<=tt)
	{
		auto t=q[hh++];
		int a=t.a;
		int b=t.b;
		int c=t.c;

        
        //a to b 
		insert(a - min(a ,B - b),min(a + b, B ), c);
		//a to c
		insert(a - min(a, C - c), b, min(C , c + a));
		//b to a;
		insert(min(A,a+b),b-min(b,A-a),c);
		//b to c
		insert(a,b-min(b,C-c),min(c+b,C));
		//c to a;
		insert(min(A,a+c),b,c-min(A-a,c));
		//c to b
		insert(a,min(b+c,B),c-min(B-b,c));
		
		
	}
	
}

int main()
{
	cin>>A>>B>>C;
	//cout<<A<<B<<C;
	bfs();
	//cout<<vis[0][9][1];
	for(int i=0;i<=C;i++)
		for(int j=0;j<=B;j++)
			if(vis[0][j][i])
			{
				cout<<i<<" ";
			}
	 
	return 0;
} 
