/*
������֪QWQ�������Ѿ����˶�����ܵĵز���ĳ��һλ����̩̹�ǵ���ʿǰ����QWQ������ս��������ս����Ŀȴ�ǳ���֣�
��λ��ʿҪ��QWQ��һ��n x n��С�������Ϸ���k�����ӣ���Ҫ����ú��������ÿһ�к�ÿһ�������һ�����ӣ���Ȼ�����������˵ļ򵥣�
������λ��ʿҪ��QWQ��������������ֹ��ж����֣�
���ܰ���QWQ����������ô��
Input
ÿ������ռ��һ��
һ������������ �ֱ��ʾ���̵Ĵ�Сn��Ҫ����õ�����k
0<n<9 , 0<k<=n
Output
ÿ������ռ��һ��
�����������ֵ�������Ŀ
Sample Input
����һ��
2 1

��������
2 2
Sample Output
����һ��
4

��������
2
*/

#include<bits/stdc++.h> 

using namespace std;

void putpos(int r,int c)
{
	
}

int main()
{
	int n,k;
	cin>>n>>k;
	//bulid a nxn's qipan ,initial value is 0
	int s[n][n];
	//once decide a pos,del c and r
	int solution=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int tmp=k;
			if(s[i][j]==0)
			{
				s[i][j]=1;
				s[i][n]=1;
				s[n][j]=1;
				tmp--;
				while(tmp)
				{
						
				}
			}
		}
	}
	return 0;
}

