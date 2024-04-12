#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

//���߶�����������Զ���Ϊ���ֵ

int w[N];//ԭ���� 

int n,m;

struct Node
{
	int l,r;
	int maxv;
}tr[N*4]; 

//���� 
void build(int u,int l,int r)
{
	if(l==r)tr[u]={l,r,w[r]};//���l==r�Ǿ���Ҷ�ڵ㣬ֱ�Ӹ�ֵ 
	else
	{
		//����Ļ��ȸ�ֵ����uΪ���ڵ������ 
		tr[u]={l,r};//�ȼ��� tr[u]={l,r,0};
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);//u<<1|1����u*2+1
		tr[u].maxv=max(tr[u<<1].maxv,tr[u<<1|1].maxv);
		
	}
}

int query(int u,int l,int r)
{
	if(tr[u].l>=l && tr[u].r<=r)return tr[u].maxv;
	
	int mid=tr[u].l+tr[u].r>>1;//ע����tr[u].l+tr[u].r������l+r>>1����Ϊ��ǰ������е�����������е� ,�����ǲ�ѯ��������յ� 
	int maxv=INT_MIN;
	if(l<=mid)maxv=max(maxv,query(u<<1,l,r));
	if(r>=mid+1)maxv=max(maxv,query(u<<1|1,l,r));	
	return maxv;
}

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	
	build(1,1,n);
	
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int t=query(1,l,r);
		printf("%d\n",t);
	}
	
	return 0;
} 
