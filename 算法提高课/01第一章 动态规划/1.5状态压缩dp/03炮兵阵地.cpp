#include<bits/stdc++.h>

using namespace std; 

const int N=13,M=1<<N;

int g[130];

int n,m; 

int f[2][M][M];

vector<int>legal;
//vector<int>trans[M];

int cnt[M];

bool check(int state)
{
	for(int i=0;i<m;i++)
	{
		if(state>>i&1 && (state >> i+1 &1 || state >>i+2 &1))return false;//������һ�еĺϷ�״̬ 
	}
	return true;
}

int count(int state)
{
	int res=0;
	while(state)
	{
		if(state&1)res++;
		state=state>>1;
	}
	return res;
} 

int main()
{
	int n,m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)//��Ϊ�����Ʊ�ʾҪ�ӵ�0λ��ʼ������jֻ�ܴ�0��ʼ 
		{
			char k;
			cin>>k;
			if(k=='H')g[i]+=1<<j;//��ΪH���൱��ɽ�£����ܷ��ڱ� 
		}
	}
	
	//Ԥ����Ϸ�״̬
	for(int i=0;i< 1<<m;i++)
	{
		if(check(i))
		{
			legal.push_back(i);
			cnt[i]=count(i);
		}
	} 
	
	//Ԥ����Ϸ�ת��״̬ͬʱ����dp 
	for(int i=1;i<=n+2;i++)
	{
		//ö�����е�״̬ 
		for(int j=0;j<legal.size();i++)
		{
			for(int k=0;k<legal.size();k++)
			{
				for(int u=0;u<legal.size();u++)
				{
					int a=legal[j];//��ǰ�� 
					int b=legal[k];//��һ�� 
					int c=legal[u];//������ 
					if(a & b || a&c || b&c)continue;//���ж����ܳ������ڱ���һ��
					//���־Ͳ��ǺϷ���ʽ��ֱ��continue��һ�� 
					
					//�ڱ����ܷ���ɽ����
					if(g[i-1] &a || g[i]&b) continue;
					
					//����Ϸ��ͽ���״̬ת��
					
					f[i&1][j][k]=max(f[i&1][j][k],f[i-1 &1][u][j]+cnt[b]);
					
				}
			}	
		}	
	} 
	
	cout<<f[n+2&1][0][0]<<endl;
	
	return 0;
} 
