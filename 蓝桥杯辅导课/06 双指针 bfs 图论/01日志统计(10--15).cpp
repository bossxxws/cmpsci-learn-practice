#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

//priority_queue<int,vector<int>,greater<int>>res;

typedef pair<int,int> PII; 

bool res[N];

#define x first
#define y second

PII a[N];

int n,d,k;

int main()
{
	
	scanf("%d%d%d",&n,&d,&k);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);//����ʱ���id 
	}	
	
	sort(a+1,a+n+1);//��ʱ���С��������
	
	for(int i=1;i<=n;i++)
	{
		//�����ʱ��ts��ʼ��һֱ��ts+Dʱ�� 
		int t=a[i].x;//��ʼʱ�� 
		int me=a[i].y;//Ҫͳ�Ƶı�� 
		int cnt=0;//ֻ�㵱ǰ��ŵĴ��� 
		int f=i;//����ָ�� 
		//cout<<t<<" "<<me<<endl; 
		//cout<<t+d<<" "<<t<<endl;
		while(a[f].x<t+d && f<=n)//ʱ�����������ʱ�� 
		{
			//cout<<(a[f].x<t+d)<<endl;
			if(a[f].y==me)cnt++;
			if(cnt>=k)
			{
				//cout<<a[f].y<<" "<<me<<endl;
				res[me]=true;
				break;
			}
			f++;
		}
	} 
	
	for(int i=1;i<1e5;i++)if(res[i])cout<<i<<endl;
	
	return 0;
 } 
 /*
7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3

1
3
 */
