#include<bits/stdc++.h>

using namespace std;

int n,m,t;
 
queue< pair<string,int> >q;

int main()
{
	//n�ˣ�m�ǿ�ʼ���˵ı�ţ�t������ʼ�������� 
	cin>>n>>m>>t;
	
	//¼����� 
	for(int i=1;i<=n;i++)
	{
		string name;
		cin>>name;
		
		pair<string,int> pi={name,i};
		q.push(pi);
	}
	
	//��������m���� 
	for(int i=1;i<m;i++)
	{
		auto p=q.front();
		q.pop();q.push(p);
	}
	//cout<<"----11"<<q.front().first<<endl;
	while(q.size()!=1)
	{
		//��ʼ���� 
		if(t%7==0 || t%10==7)
		{
			//cout<<"---"<<endl<<q.front().first<<t<<endl;
			q.pop();//�뿪 
			t++; 
		}
		else
		{
			pair<string,int> px=q.front();
			q.pop();q.push(px);
			t++;
		}
	}
	
	cout<<q.front().first;
	return 0;
}
