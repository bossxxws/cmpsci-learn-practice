#include<bits/stdc++.h>

using namespace std;

int n;

int g[20][20];
int p[8][8];
int s[20][20];

bool draw(int x,int y)
{
	memcpy(s,g,sizeof s);//��g�������� 
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(p[i][j])
			{
				int a=x+i-1;
				int b=y+j-1;
				s[a][b]++;
				if(s[a][b]==2)return true;
			}
		}
	} 
	return false;
}
int main()
{
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<=10;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	
	
	for(int i=1;i<=4;i++)
	{

		for(int j=1;j<=4;j++)
		{
			scanf("%d",&p[i][j]);

		}
	}
	
	cin>>n;//�����ĵ�һ���Ǳ������ĵ�n��
	
	//Ϊ�˸��õĴ���߽磬��������Ūһ��ػ�
	for(int i=1;i<=10;i++)g[16][i]=1;
	
	//ö��ÿһ�� 
	for(int i=1;i<=15;i++)
	{

			if(draw(i,n))
			{
				draw(i-1,n);
				break;
			}

	}
	 
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<=10;j++)
		{
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	 
	return 0;
}
