#include<bits/stdc++.h>

using namespace std;

//f[i][j]��ʾѡi�������ܺ�Ϊj�ļ��ϣ����ԣ�MAX

const int N=103;

int w[N];

int f[N][10010];

int main()
{
    int n,m;
    
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=0;i<=n;i++)f[i][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            
            if(j>=w[i])f[i][j]+=f[i-1][j-w[i]];
        }
        
        
    }
    
    cout<<f[n][m];
    
    return 0;
}
