#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=1e5+10;

int x[N],y[N];//�洢x��y���� 

int n;
//�൱�� n ����ͬ������ǰ׺�� 
// 1 1 1 1 2 �൱�� ����  ��i-stx-1��*��i-stx-1+1��������ô���� 
// 3+2+1

int main()
{
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	} 
	
	sort(x,x+n);
	sort(y,y+n);
	
	int stx=0,sty=0;
	
	LL sum=0;
	
	for(int i=1;i<n;i++)
	{
		if(x[stx]!=x[i])
		{
			sum+=(LL)(i-stx)*(i-stx-1)/2;//������ + ĩ� * ����/2 
			stx=i;
		}
		
		if(y[sty]!=y[i])
		{
			sum+=(LL)(i-sty)*(i-sty-1)/2;
			sty=i;
		}
	}
	//�����ܵ�n-1��ʱ��û���� ����˵ 9 9 9 9 һֱ��n-1���һ��
	//x��i��û�в����� x��stx�� 
	//������ 9 9 9 9 10��ʽ�ģ������·�ʽ��Ҳ����� 
	//��Ϊ��n�������ڣ�����n��Ҳ�൱��һ��������ǰ��ģ�����sum+=0 
	
	sum+=(LL)(n-stx)*(n-stx-1)/2;
	sum+=(LL)(n-sty)*(n-sty-1)/2;
	
	cout<<sum<<endl;
	return 0;
}
