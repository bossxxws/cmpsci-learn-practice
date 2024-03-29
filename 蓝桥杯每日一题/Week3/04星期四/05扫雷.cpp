#include<bits/stdc++.h>

using namespace std;

const int N=999997,M=999997,X=1e9+1;

const int maxmax=-1;

int n,m;

typedef long long LL;

LL h[M];//��ϣ���� (ֻ������һ�½��б��)

bool st[N];//�ж��Ƿ���ʹ� 

struct ids
{
	int snumber=0;
	int sr=-1;	
};

ids id[M];
int res=0;//id�洢ĳ��λ���ϵ���Ϣ :�м������ף����뾶�Ƕ��� 
 
LL get_hash_number(int x,int y)
{
	return (LL)x*X+y;
}//Ϊ����ת��Ϊ��һ�޶��ܷ��µĵı�� ����Ϊx��y��ӻᱬint�������������ⷽ��ת����ϣ
//����������ĵ�ַ��Ϣת��Ϊһ�����ĵ�ַ��ϢΪ��ѡַ 

int find(int x,int y)
{
	LL t=get_hash_number(x,y);//�õ������� 
	int key=(t%M+M)%M;//ת��Ϊ��һ�޶��ܷ��µĵı�� 
	if(h[key]!=maxmax && h[key]!=t)
	{
		key++;
		if(key==M)key=0;
	}
	return key;
}

bool check(int x1,int y1,int x2,int y2,int r)
{
	int d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);	
	return d<=r*r;
} 

/*
void insert(int x,int y)
{
	int key=find(x,y);
	h[key]=get_hash_number(x,y);
}
*/

void dfs(int x,int y,int r)
{
	//cout<<"yes";
	for(int i=-r;i<=r;i++)
		for(int j=-r;j<=r;j++)
		{
			int nx=x+i;
			int ny=y+j;
			int t=find(nx,ny);
			//cout<<nx<<" "<<ny<<endl;
			if(!st[t] && id[t].snumber && check(x,y,nx,ny,r))//(x,y)Ϊ��ըԲ������ 
			{
				res+=id[t].snumber;
				int nr=id[t].sr;
				st[t]=1;
				//cout<<nx<<" "<<ny<<endl;
				//cout<<nr;
				dfs(nx,ny,nr);//nx,ny����ĵ��ױ�ը����ը�뾶��nr 
			}
		}
}


int main()
{
	memset(h,-1,sizeof h);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		int x,y,r;
		scanf("%d%d%d",&x,&y,&r);
		LL t =get_hash_number(x,y);
		int key=find(x,y);
		h[key]=t;
		id[key].snumber++;
		id[key].sr=max(id[key].sr,r);
	}
	
	//ö�ٵ���
	for(int i=0;i<m;i++)
	{
		int xx,yy,rr;
		scanf("%d%d%d",&xx,&yy,&rr);
		dfs(xx,yy,rr);
	}
	
	cout<<res;
	return 0;	
} 
/*
2 1
2 2 4
4 4 2
0 0 5

2
*/
