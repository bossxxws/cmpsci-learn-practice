#include<bits/stdc++.h>

using namespace std;

const int N=100;//����С���־�Ҫ�뵽���������� 

int m;
int n,k;
int pack[N][N];
int st[N];
unordered_set<int>cole;
//����ö��ٸ����������˶��ٸ� �����༯���˶��� 
bool dfs(int aim,int cnt,int kind)
{
	if(kind>=m)return true;
	if(cnt>aim)return false;
	for(int i=0;i<n;i++)
	{
		 if(!st[i])
		 {
		 	st[i]=true;
		 	for(int j=0;j<k;j++)
		 	{
		 		cole.insert(pack[i][j]);	
			}
		 	int t=cole.size();
		 	if(dfs(aim,cnt+1,t))return true;
		 	st[i]=false;
		 	cole.clear();
		 }
	}
	return false;
} 

int main()
{
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			scanf("%d",&pack[i][j]);//��i�� k����ζ 
		}		
	}
	//��������m/k��
	int cnt=m/k+1;
	//cout<<cnt;
	//cout<<dfs(cnt,0,0);
	while(true)
	{
		if(cnt>n)
		{
			cout<<-1;
			break;
		}
		if(dfs(cnt,0,0))
		{
			cout<<cnt;
			break;
		}
		cnt++;
	} 

	return 0;	
} 
