//1e9+7����һ������
#include<bits/stdc++.h>

using namespace std;

//����Ѱַ��һ�㿪������
//�ҳ�200000֮���һ������
/*
for(int i=2*1e5;;i++)
{
	bool flag=true;
	for(int j=2;j*j<=i;j++)
	{
		if(i%j==0)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<i;
		break;
	}
}
*/ 

const int N=200003,null=0x3f3f3f3f;
//һ�������ֵ����0x3f3f3f3f,��Լ��1e9��һЩ 
//��null�������ʾλ����û�����֣�null�����������Ŀ�������ַ�Χ֮�⣬����˵�����������
//������õ��������ַ�Χ֮�ڣ����ܻ���ɴ����жϣ�����û����������ÿ����λ�ö���������� 
int h[N];

int find(int x)
{
	int k=(x%N+N)%N;
	while(h[k]!=null && h[k]!=x)
	{
		k++;
		if(k==N)k=0;//���涼û�оʹ�ͷ��ʼ��
	}	
	return k;
}

void insert(int x)
{
    int t=find(x);
	h[t]=x;
}

int main()
{
	int n;
	cin>>n;
	
	memset(h,0x3f,sizeof h);//memset�ǰ����ֽ���set�ģ�
	                        //����˵int���ĸ��ֽڣ���ÿ���ֽڶ���0x3f����Ϊ0x3f3f3f3f
	
	while(n--)
	{
		char op[2];
		int x;
		cin>>op;
		cin>>x;
		if(*op=='I')
		{
			insert(x);
		}
		else
		{
			int k=find(x);
			if(h[k]!=null) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	
	return 0;
}
