//dfs����ö�ٰ�ÿһ����ɾ��֮��ʣ����һ������ͨ���е�Ĵ�С
//�Ƚϵ���ʣ���һ���֣�ʣ�ಿ�ֱض���ͨ����һ����ͨ�飬���Ҳ�����ɾ���ĵ㣩
//�����ҳ���С����ͨ���С����
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10,M=N*2;
int n,m;
int h[N],e[M],ne[M],idx;//�ڽӱ��ʾ����h[N]����Ƕ��ͷ ���������ڲ������޹ؽ�Ҫ
bool st[N];//�洢��Ǳ������ĵ� 
int ans=N; 

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;//ͷ�巨 
}

//����ͼ��������ȱ��� 
//��uΪ������ͨ��ĵ������ 
int dfs(int u)//u��ʾdfs���ĵ� 
{
	st[u]=true;//�Ѿ����ѹ���
	int sum=1;
	int res=0;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(!st[j])
		{
			int s=dfs(j);
			res=max(res,s);//��sΪ��������s������ͨ���е������
			sum+=s;
		}
	}//��������sumΪ��uΪ��������u������ͨ���е����������uҪɾ���ģ����Բ��ܰ���u��ѡ��������ͨ������
	
	res=max(res,n-sum);//res�������ͨ������ĵ���
	
	ans=min(ans,res);//ans ȡ�����з����������ͨ������������  ��С�İ�������
	
	return sum;
}

int main()
{
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);//���������˵��������
		add(b,a);
		
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
