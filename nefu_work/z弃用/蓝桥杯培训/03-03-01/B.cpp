#include<bits/stdc++.h>

using namespace std;

int N,K,P;
//N��

//K��ֽ��
//����K/N��good
//ʣ�µ�ȫ��bad

//ÿ��ϴP���� 
 
//��M��С����λ��

queue<int> q;
 
int main()
{
	scanf("%d%d%d",&N,&K,&P);
	
	for(int i=1;i<=K;i++)q.push(i);
	
	int m=K/N;
	
	priority_queue<int,vector<int>,greater<int>> pri;
	
	//���m��	
	int cnt=0;//�㵽���к�����Ϊֹ 
	while(cnt<m)
	{
		int n=N-1;
		
		//һ�� 
		while(n>0)
		{
			//���� 
			n--;
			q.pop();
			//ϴ�� 
			for(int i=0;i<P;i++)
			{
				int a=q.front();q.pop();
				q.push(a); 
			}
		}
		//�ֵ��Լ�
		//cout<<q.front()<<endl;
		
		pri.push(q.front());
		
		q.pop();
		for(int i=0;i<P;i++)
		{
			int a=q.front();q.pop();
			q.push(a); 
		}
		cnt++;
	}
	
	while(pri.size())
	{
		cout<<pri.top()<<endl;
		pri.pop();
	}
	return 0;
}
