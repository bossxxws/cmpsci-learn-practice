#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int a[N];

int f[N];

//ÿ�ζ�������½�������
//��������껹�У���Ҫ�����ع���ȥ��
//����ǵ�һ��������صĵ�����
//����������Ҫ�䱸���ٸ�ϵͳ�����������е���
 
int main()
{
	
	vector<int> a={0};
	//int h=1;
	int t;
	while(cin>>t)
	{
		
		//a[h++]=t;
		a.push_back(t);
	}


	//��½�������	
	for(int i=a.size()-1;i>=0;i--)
	{
		
		f[i]=1;
		
		for(int j=a.size()-1;j>i;j--)
		{
			
			if(a[j]<=a[i])f[i]=max(f[i],f[j]+1);
			
		}
		
	}
	
	int res=-1;
	
	for(int i=1;i<a.size();i++)res=max(res,f[i]);
	
	//cout<<h<<endl;
	////for(int i=1;i<h;i++)cout<<a[i]<<endl;
	cout<<f[6];
	
	return 0;
} 
