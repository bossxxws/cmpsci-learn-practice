#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

struct range
{
	int l,r;
}dat[N];

bool cmp(range a,range b)
{
	return a.l<b.l;
}

int main()
{
	//���� �߶� 
	int star,end;
	cin>>star>>end;
	
	//����n������ 
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		dat[i]={l,r};
	}
	
	sort(dat,dat+n,cmp);	
		
	//�����˫ָ��ģ��
	//for + while 
	int st=star; 
	int res=0;
	bool f=false;
	for(int i=0;i<n;i++)
	{
		int j=i,ed=-2e9;
		while(j<n && dat[j].l<=st) 
		{
			ed=max(dat[j].r,ed);
			j++;//ѡ���ܸ���st������Ҷ˵���� 
		}
		
		//ed�ʼΪ��������û������˵��û����˵�С��star�����䣬������star
		//�Ƚϣ����С��star�ͱ�ʾû���Ҷ˵����star������ 
		if(ed<st)
		{
			res=-1;
			break;
		}
		
		//����st���ɹ���һ�����䣬res++ 
		st=ed;
		res++;
		
		if(st>=end)
		{
			f=true;
			break;
		} 
		
		i=j-1;
	} 
	
	if(!f)cout<<-1<<endl;
	else cout<<res<<endl;
	return 0;
}
