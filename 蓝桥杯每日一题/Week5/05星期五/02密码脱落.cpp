#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5;

int n;

char a[N];

int f[N][N];//��i��jΪ���˵������е�������ַ������� 

int main()
{

	scanf("%s",a+1);

	
	int n=strlen(a+1);
	
	//cout<<n<<endl;
	
	for(int len=1;len<=n;len++)//ö�����䳤�� 
		for(int l=1;l+len-1<=n;l++)//ö����˵�
		{
			int r=l+len-1;
			if(len==1)f[l][r]=1;//�������һ�������ַ���
			else
			{
				f[l][r]=max(f[l+1][r],f[l][r-1]);
			
				if(a[l]==a[r])f[l][r]=max(f[l][r],f[l+1][r-1]+2);
			}

		} 
	
	cout<<n-f[1][n]<<endl;
	
	return 0;
} 
