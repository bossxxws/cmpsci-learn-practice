#include<bits/stdc++.h>

using namespace std;

int a[N];


int DFS(int depth,)
{
	
}

int main()
{
	int n;
	
	while(cin>>n && n!=0)
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		
		//��������Ƚϸ��ӣ�״̬���Ա�ʾ�����ز�©�ر�ʾÿһ��״̬�� 
		//����˵ʹ��DFS����������ÿһ����� 
		
		//��������||ȫ�ֱ��� 
		
		int depth=0;
		
		while(!DFS(depth,0,0))depth++; 
		
		
		cout<<depth;
	} 
	return 0;
} 
