#include<bits/stdc++.h> 

using namespace std;

#define x first
#define y second

char a[5][5],b[5][5];

typedef pair<int,int> PII;

void turn_one(int x,int y)
{
	if(a[x][y]=='+')a[x][y]='-';
	else a[x][y]='+';
}

void turn_all(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		turn_one(i,y);
		turn_one(x,i);
	}//这里 x,y这个位置被操作了两次
	//所以我们还要操作一次
	turn_one(x,y); 
}

int getstatus(int x,int y)
{
	return x*4+y;
}

int main()
{
	for(int i=0;i<4;i++)
		{
			scanf("%s",a[i]);
		} 
	
	vector<PII> res; 
	
	for(int op =0;op<1<<16;op++)
	{
	 	vector<PII>tmp;
	 	
	 	memcpy(b,a,sizeof b);//把a拷贝到b（b是备份，一会儿用来还原a） 
	 	
	 	for(int i=0;i<4;i++)
	 		for(int j=0;j<4;j++)
	 		{
	 			int status=getstatus(i,j);
	 			if(op>>status&1)//要操作 
	 			{
	 				turn_all(i,j);
	 				tmp.push_back({i,j});
				}
			}
	 	bool f=true;
	 	for(int i=0;i<4;i++)
	 		for(int j=0;j<4;j++)
	 		{
	 			if(a[i][j]=='+')
	 			{
	 				f=false;
					break;	
				}
			}
		if(f)
		{
			if(res.empty() || res.size()>tmp.size() )res=tmp;
		}
		memcpy(a,b,sizeof b);
	}	
	cout<<res.size()<<endl;
	for(auto t:res)cout<<t.x+1<<" "<<t.y+1<<endl;	
	return 0;
}
