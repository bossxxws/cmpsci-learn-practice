#include<bits/stdc++.h>
using namespace std;

int n;

const int N=1003;//����������
const int M=1003;//���������� 

int mar[N];//������һ��ͳ�Ʋ�����λ�� 

int a[M][M];//�洢��i�������ĵ�i�β������״̬ ��

bool drop[2*M];//ģ�⻷�ε�״̬ 

int s[N][N];//ǰ׺������洢�߹��ĸ��� 

int op[N];

int main()
{
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;//�������� 
		op[i]=m;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);//d[i]��1����ʾ��i�ù�����ʼ״̬ 
			if(a[i][j]>0)mar[i]=j,s[i][j]=s[i][j-1];//���һ��ͳ�Ʋ����ǵ�j�� 
			else s[i][j]=s[i][j-1]+a[i][j]; 
//			cout<<s[i][j]<<endl;
		}
	}
//	cout<<"cin over"<<endl;
	//����T
	int sum=0;
	int D=0;
	for(int i=1;i<=n;i++)
	{
		int j=mar[i];//���һ��ͳ�Ƶ��±� 
//		cout<<"mar "<<j<<endl; û���� 
		int sou=a[i][j];//���һ��ͳ�Ƶĸ���
//		cout<<sou<<endl;û���� 
//		cout<<sou+s[i][op[i]]-s[i][j]<<endl; !!!
		sum+=sou+s[i][op[i]]-s[i][j];
		
		//����������������� 
		for(int k=1;k<=op[i];k++)
		{
			int sta;
			if(k==1)sta=a[i][k];
			else sta=a[i][k-1];
			
			int p=k;
			
			while(p<op[i] && a[i][p]<=0)p++;//�ߵ�ͳ�Ƶĵط�
			
//			cout<<i<<" "<<k<<" "<<p<<" "<<sta<<" "<<s[i][p]-s[i][k-1]<<endl;
			if(p==op[i] && a[i][p]<=0)break;
			if(a[i][p]!=sta+(s[i][p]-s[i][k-1]))
			{
//				cout<<i<<" "<<
//				a[i][k-1]<<" "<<k-1
//				<<" "<<p<<" "<<
//				a[i][p]<<" "<<sta+(s[i][p]-s[i][k-1])<<endl;
				drop[i]=true;	
				drop[i+n]=true;
				D++;
				break; 
			} 
			k=p;
		}
	} 
	int E=0;

	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		if(drop[i]==true)
		{
			cnt++;
			int j=i+1;
			while(j<=2*n && drop[j]==true && cnt!=3)j++,cnt++;
			if(cnt==3)E++;
//			cout<<i<<" "<<j<<endl;
		}
	}

	
	cout<<sum<<" "<<D<<" "<<E;
	
	return 0;
}
