#include<bits/stdc++.h>

using namespace std;

int n; 
const int N=103;

//20�� һ��һ��


int a[N];

int g[22][6];
int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=20;i++)g[i][6]=5;//��ʾ��һ��ʣ�µ���λ 
	
	//�������
	
	for(int i=1;i<=n;i++)
	{
		int need=a[i];
//		cout<<"need "<<need<<endl;
		int cnt=0;
		for(int j=1;j<=20;j++)//ö��ÿһ�� 
		{
			if(cnt==need)break;
			if(g[j][6]>=need)
			{

				for(int k=1;k<=5;k++)
				{
					if(g[j][k]==0)
					{
						g[j][k]=1;
						g[j][6]--;
						cnt++;
						cout<<5*(j-1)+k<<" "; 
//						cout<<cnt<<"  cnt "<<endl;
						if(cnt==need)break;
					}
				}

			}
		}
		
		if(cnt==0)//���û��������λ�� 
		{
			for(int j=1;j<=20;j++)
			{
				if(cnt==need)break;
				for(int k=1;k<=5;k++)//��С�����п�λ�Ͱ��� 
				{
					if(g[j][k]==0)
					{
						g[j][k]=1;
						g[j][6]--;
						cnt++;
						
						cout<<5*(j-1)+k<<" "; 
						if(cnt==need)break; 
					}
				}
			}
		} 
//		if(i==39)cout<<cnt<<" "<<need<<endl;
		cout<<endl;
	} 
	return 0;
} 
