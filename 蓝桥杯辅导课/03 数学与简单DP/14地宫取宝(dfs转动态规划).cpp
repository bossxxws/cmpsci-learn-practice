#include<bits/stdc++.h>

using namespace std;

const int MOD=1000000007;

const int N=52;

typedef long long LL; 

int n,m,k;

int a[N][N];
int f[N][N][N][N];

LL ans=0; 

//����ȷ��ά�� ͨ��dfs����֪��һ��״̬�������ĸ�ά�ȱ�ʾ��
//����x �� y Ŀǰ�ı������ֵmaxvalue ����Ŀǰ�ı�������cnt
//ȷ�����Եķ�Χ��
//cnt==k��ʱ���ֹ
//x=n && y=m ��ʱ���ֹ 
//��ʼ��״̬��x==1 y==1 maxvalue==-1(��Ϊ�տ�ʼ����û�б��������еı�����ֵΪ0������ѡ���Բ�ѡ) cnt==0 
//x [1 -- n]
//y [1 -- m] 
//maxvalue[-1 -- 12](ȡ���ֵ)
//cnt[1 -- k] 


/*
��1��dp���ά�ȣ���״̬�ɼ�������Ψһȷ����
��2��ȷ����ĸ���ά�ȵ�ȡֵ��Χ��
��3��ȷ��Ŀ��ֵ��dp���е�λ�á�
��4�����ݵݹ���ֹ������ȷ��dp��ĳ�ʼ״̬��
��5��ȷ��dp��������һ��λ�õ�ֵ���������λ�õ�������ϵ����״̬ת�Ʒ��̡�
*/

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]++;
		}
	//f��ʾ��i j���λ�ã����ֵΪmaxvalue��ȡ��������Ϊk�ķ����� 
	f[1][1][0][0]=1;//��һ��λ�ò��õķ�����Ϊ1 
	f[1][1][a[1][1]][1]=1;//��һ��λ���õķ�����Ϊ1 

	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++)
			for(int maxvalue=0;maxvalue<=13;maxvalue++)//����-1û������������˵Ҫ��0��ʼ�����еı�����ֵ+1 
				for(int cnt=0;cnt<=k;cnt++)
				{
					//����ȡ���Բ�ȡ����� 
					if(cnt>0 && maxvalue==a[i][j])//cnt>0��ʾȡ
					//��ǰ��һ�������f[i][j][maxvalue][cnt]��ȡ��[i,j]λ�ñ���֮���״̬��Ҫ��֤a[i][j]==maxvalue��f[i][j][maxvalue][cnt]
					//ȡ����maxvalue�ķ��� 
					{
						 
						//��ȡ��ʱ����ת�Ƶ� f[i][j][maxvalue][cnt]��˵����һ��״̬�����ֵҲ��maxvalue 
						
						//ȡ��ʱ����һ��״̬�����ֵһ��С��maxvalue�����ҿ���ֱ��ת�Ƶ�maxvalue 
						//���ǰ���󱦱�ֵС��maxvalue�ġ�������Ϊcnt-1�ķ����������ۼ�һ��
						//ת�Ƶ���󱦱�ֵ����maxvalue��������Ϊcnt��״̬ 
						for(int s=0;s<maxvalue;s++)
						{
							f[i][j][maxvalue][cnt]=(f[i][j][maxvalue][cnt]+f[i][j-1][s][cnt-1])%MOD;
							f[i][j][maxvalue][cnt]=(f[i][j][maxvalue][cnt]+f[i-1][j][s][cnt-1])%MOD;
						}
						
					}
					
					//��ȡ����� 
					f[i][j][maxvalue][cnt]=(f[i][j][maxvalue][cnt]+f[i][j-1][maxvalue][cnt])%MOD; 
					f[i][j][maxvalue][cnt]=(f[i][j][maxvalue][cnt]+f[i-1][j][maxvalue][cnt])%MOD;

				}
	LL res=0;
	for(int i=0;i<=13;i++)
	{
		res=(res+f[n][m][i][k])%MOD;
	} 
	cout<<res;
	return 0;
};
/*
2 2 2
1 2
2 1

2

2 3 2
1 2 3
2 1 5


14

*/


/*
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=m;j++)
	{
		cout<<a[i][j]<<" ";
	} 
	cout<<endl;
}
*/

