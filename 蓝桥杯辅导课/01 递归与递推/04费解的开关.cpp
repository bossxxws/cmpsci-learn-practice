#include<bits/stdc++.h>

using namespace std;

const int N=6;

//��һ�еĲ���ѡ�����ܾ�������ͼ��״̬
//���鿴���һ����û����ľ�֪���ɲ����� 
char a[N][N];

//op�����һ��ĳ��λ�ò������ 

int n;

char backup[N][N];

int dx[]={-1,1,0,0,0};
int dy[]={0,0,-1,1,0};

void turn(int x,int y)
{
        for(int i=0;i<5;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if( nx<0 || ny<0 || nx>4 || ny>4 )continue;//���Ϸ���Ϊֱ������
			
			//�ַ�0��ASCII����48 -- 110000
			//�ַ�1��ASCII����49 -- 110001
			//����Ҫ��0���1��1���0���Ǿ�ֱ���������ˣ�����ǲ���λ�ļӷ���
			a[nx][ny]^=1;
			//if(a[nx][ny]=='0') a[nx][ny]='1';
			//else if (a[nx][ny]=='1')a[nx][ny]='0';
		}
}

int main()
{
	cin>>n;
	while(n--)
	{
	    //cout<<n;
		for(int i=0;i<5;i++)scanf("%s",a[i]);

		int res=100;

		for(int op=0;op<32;op++)
		{
			int step=0;
			memcpy(backup,a,sizeof a);
			for(int i=0;i<5;i++)
			{
				if(op>>i&1)
				{
					step++;
					turn(0,i);//��i��λ�ò���һ�� 
				}
			}
			//��һ�еĲ���ö����һ����
			//������ͨ����һ�е�״̬��������һ�� 
			for(int i=0;i<4;i++)//���������ڶ��У�������������һ�� 
			{
				for(int j=0;j<5;j++)
				{
					if(a[i][j]=='0')
					{
						step++;
						turn(i+1,j);//�����·��Ĳ���һ�£���һ���Ǵ򿪣� �Ա���������� 
					}
				}
			}

			//�ж����һ����û�а���
			bool f=true;
			for(int i=0;i<5;i++)
			{
				if(a[4][i]=='0')
				{
					f=false;
					break;	
				}	
			} 
			if(f)
			{
				res=min(res,step);
			}
			memcpy(a,backup,sizeof backup);
			//cout<<step;
		}

		if(res<=6)cout<<res<<endl;
		else cout<<-1<<endl; 

	
	}
	return 0;
}
