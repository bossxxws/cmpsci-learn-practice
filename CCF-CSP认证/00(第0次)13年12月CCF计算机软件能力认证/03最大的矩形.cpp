#include<bits/stdc++.h>

using namespace std;

int n;
int h[1010]; 
int maxv=-1;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	
	int l=1;
	for(int i=l;i<=n;i++)//ö����˵� 
	{
		for(int j=1;j+i-1<=n;j++)//ö�����䳤�� 
		{
			int minh=5e4;
			int r=j+i-1;//�ó��Ҷ˵� 
			for(int k=i;k<=r;k++)//ö�����������ĸ߶�
			{
				if(h[k]<minh)minh=h[k];
			}
			//����������
			int s=j*minh; 
			//cout<<s<<" "<<j<<" "<<minh<<endl;
			if(s>maxv)maxv=s;
		}
	}
	cout<<maxv;
	return 0;
}
