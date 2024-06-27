#include<bits/stdc++.h>

using namespace std;

const int N= 30; 
int n;

int w[N];

int f[N][N];
int g[N][N];

//输出树的前序遍历
//前序遍历顺序：root->left->right
void dfs(int l,int r)
{
	if(l>r)return ;//如果l>r则表示当前的子树已经遍历完成
	//否则输出当前子树的最优根
	//root
	int root=g[l][r];
	cout<<root<<" ";
	//然后以当前子树的最优根为边界，划分左子树和右子树
	//left
	dfs(l,root-1);
	//right
	dfs(root+1,r);

}

int main()
{
	cin>>n;

	for(int i=1;i<=n;i++)cin>>w[i];

	for(int len=1;len<=n;len++)
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			if(len==1)
			{
				f[l][r]=w[l];
				g[l][r]=l;
			}
			else
			{
				for(int k=l;k<=r;k++)
				{
					int left=k==l?1:f[l][k-1];
					int right=k==r?1:f[k+1][r];
					int score=left*right+w[k];
					if(f[l][r]<score)
					{
						f[l][r]=score;
						g[l][r]=k;
					}
				}
			}
			
		}
	cout<<f[1][n]<<endl;
	dfs(1,n);
	return 0;
}
