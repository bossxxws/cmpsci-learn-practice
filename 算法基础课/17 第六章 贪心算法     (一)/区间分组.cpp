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
	int n;
	cin>>n;
	
	//��������
	for(int i=0;i<n;i++)
	{
		int l,r;
		cin>>l>>r;
		dat[i]={l,r};
	} 
	
	sort(dat,dat+n,cmp);
	
	priority_queue<int,vector<int>,greater<int>> heap;//С���Ѷ��巽ʽ
	//С����ά����������С��r 
	
	//heap�����ÿ�������������Ҷ˵�
	for(int i=0;i<n;i++)
	{
		auto t=dat[i];
		//������heap.top()�Ƚϣ�����Ҷ˵��ǰ���飬�����ܲ���������и��࣬��̰�ģ�
		//�����ԭ���������Ҷ˵�϶�������²������������Ҷ˵��ˣ����Խ�ԭ���ĵ���
		//Ȼ����µļ���
		//�����ѻ�������򣬻�������ӵ����С����Ҷ˵����
		
		//���ܷ�����
		if(heap.empty() || t.l<=heap.top())heap.push(t.r);
		else
		{
		    //�������в�����max_r
		    heap.pop();//��ԭ��������Ҷ˵�ȥ��
		    heap.push(t.r);//�����µ�����Ҷ˵�
		} 
	}
	cout<<heap.size()<<endl;

	return 0;
}
