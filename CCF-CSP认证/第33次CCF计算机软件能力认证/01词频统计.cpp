#include<bits/stdc++.h>

using namespace std;

int n,m; 

const int N= 103;

//ͳ�����������ܹ���������i�����Ұ���i�����µĸ��� 

int a[N][N];
int lth[N];//��¼�������� 
int ma[N];
int cnt,mark;

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		cin>>lth[i];
		for(int j=1;j<=lth[i];j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	//��ʼͳ�Ƹ���,�ӵ��ʱ������ 
	for(int i=1;i<=m;i++)
	{
		cnt=0;
		bool flag=false;
		mark=0;
		for(int j=1;j<=n;j++)//ö��ÿһ������ 
		{
			for(int k=1;k<=lth[j];k++)//ö�ٵ�ÿһ�����е����һ�� 
			{
				if(a[j][k]==i)
				{
				    cnt++;
    				flag=true;
				}

			}
			if(flag)
			{
				mark++;//��¼���ִ��������µ�ƪ��
				flag=false;
			}	 
		}
		cout<<mark<<" "<<cnt<<endl;
	} 

	return 0;
} 
