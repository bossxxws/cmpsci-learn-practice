#include<bits/stdc++.h>

using namespace std;

int bfs(string start)
{
	string end="12345678x";
	
	queue<string> q;
	unordered_map<string,int> d;
	
	q.push(start);
	d[start]=0;//�ʼ��㵽�𵽾���Ϊ0
	
	int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	
	while(q.size())
	{
		auto t=q.front();
		q.pop();
		
		int distance = d[t];
		
		if(t==end) return distance;//����Ѿ�������״̬��ֱ�ӷ��� 
		
		//״̬ת��
		int k=t.find('x');
		int x=k/3,y=k%3;//ת����'x'��λ��
		
		for(int i=0;i<4;i++)
		{
			int a=x+dx[i],b=y+dy[i];//��a��b���ǣ�x��y���������ҵ�һ��λ��
		 
			if(a>=0 && a<3 && b>=0 && b<3)
			{
			    swap(t[k],t[a*3+b%3]);//����%��%3���� 
				//��x��y�����±���k ������a��b�����±��ǣ�a*3+b��
				
				if(!d.count(t))
				{
					d[t]=distance + 1;
					q.push(t);//���´�ʱ���ַ�������ת��Ϊ�Ź���״̬
				} 
				 
				swap(t[k],t[a*3+b%3]);//��ԭ״̬(Ϊ�˽��������������������ط���)������%��%3���� 
				
			}
		}
	} 
	return -1;
	
	
}

int main()
{
	string start;
	for(int i=0;i<9;i++)
	{
		char c;
		cin>>c;
		start+=c;
		 
	}
	
	cout<<bfs(start)<<endl;
	return 0;
	
} 
