#include<bits/stdc++.h>

using namespace std;

const int N=1002;

struct node
{
	int x,y,z;	
}d[N];

int t;
int n,h,r;//奶酪的数量、高度、空洞的半径 

int p[N];
int st[N]; 


int find(int x)
{
	if(x!=p[x])p[x]=find(p[x]);
	return p[x];
}

bool check(int x1,int y1,int z1,int x2,int y2,int z2)
{
    long long dd=(long long )(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
	return dd<=(long long )4*r*r;
}
/*
3 
2 4 1 
0 0 1 
0 0 3 
2 5 1 
0 0 1 
0 0 4 
2 5 2 
0 0 2 
2 0 4
y
n
n
*/
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>h>>r;
		
		for(int i=0;i<n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			d[i]={x,y,z};
			st[i]=0;
		}
		queue<node> q;
		for(int i=0;i<n;i++)
		{
			if(d[i].z<=r)
			{
				q.push(d[i]);
				st[i]=1;
			}		
		} 
		
		bool ok=false;

		while(q.size())
		{
			auto t=q.front();
			int x=t.x,y=t.y,z=t.z;
			q.pop();
			if(ok)break;
			if(z+r>=h)
			{
				puts("Yes");
				ok=1;
				break;
			}
			for(int i=0;i<n;i++)
			{
				if(st[i])continue;
				
				int nx=d[i].x,ny=d[i].y,nz=d[i].z;
                //cout<<check(x,y,z,nx,ny,nz);
				if(check(x,y,z,nx,ny,nz))
				{
					q.push(d[i]);
					st[i]=1;
					if(nz+r>=h)
					{
						ok=1;
						puts("Yes");
						break;
					}
				}

			}
			
		}
		if(!ok)cout<<"No"<<endl;
	}
	return 0;
} 
