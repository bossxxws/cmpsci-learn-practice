#include<bits/stdc++.h>

using namespace std;

const int N=53;

int f[N][N];

int ne[N];//next���� 

char str[N];//�ִ� 

const int mod=1e9+7;

int main()
{
	int n,m;
	
	cin>>n>>str+1;
	
	m=strlen(str+1);
	
	//kmp��next��ģ��
	for(int i=2,j=0;i<=m;i++)
	{
		//��ƥ������ 
		while(j && str[j+1]!=str[i])
		{
			j=ne[j]; 
		}
		 
		//ƥ��Ļ�����󹫹�ǰ��׺+1
		if(str[j+1]==str[i])j++;
		
		//��next��ֵ 
		ne[i]=j; 
	} 
	
	//dp+״̬�� 
	f[0][0]=1;//�Ѿ�ƥ����0λ����ƥ�䵽���ַ���λ�ã�״̬����0�ķ�����
	
	for(int i=0;i<n;i++)//ö������λ 
	{
		for(int j=0;j<m;j++)//ö�ٵ�iλ������ģ�崮�е�λ��	
		{
			for(int k='a';k<='z';k++)//ö�ٵ�i+1λ���ַ�
			{
				//ƥ�����:Ѱ�ҵ���i+1��λ����kʱ,���������Ѿ������˵�iλ,�Ѿ�ƥ����Ӵ���λ����jʱ,�������ĸ�λ��
				int u=j;
				while(u && str[u+1]!=k)u=ne[u];		
				
				if(str[u+1]==k)u++;
				if(u<m)f[i+1][u]=(f[i+1][u]+f[i][j])%mod;//��Ϊ���ܰ����ִ������Բ��ܵ���m
			} 
		} 
	} 
	
	int res=0;
	for(int i=0;i<m;i++) res=(res+f[n][i])%mod;
    //�����еķ�������������Ϊ�ܷ�����
    printf("%d",res);
	
	return 0;
}
