#include<bits/stdc++.h>

using namespace std;

int n,m;
//n��С���ѣ�����m�뿪 

queue<int>q;

int main()
{
	cin>>n>>m;
	
	//�γɶ��У��൱��һ�����ζ��� 
	for(int i=1;i<=n;i++)q.push(i);
	
	int cnt=0;//���� 
	
	while(q.size()!=1)
	{
		if((cnt+1)!=m)
		{
			cnt++;
			
			//�ŵ���β 	
			int a=q.front();
			q.pop();q.push(a);
		}
		if((cnt+1)==m)
		{
			cnt=0;
			q.pop(); //�뿪 
		}
	}

	cout<<q.front();
	
}
