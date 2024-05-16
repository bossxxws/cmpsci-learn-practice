//完全背包问题
#include<bits/stdc++.h>

using namespace std;

const int N=1003;

int w[5];

int f[N];//f[i][j]表示选i本书，容量为j的选法

int main()
{
    w[1]=10,w[2]=20,w[3]=50,w[4]=100;
    
    int n;
    cin>>n;//背包容量
    
    f[0]=1;
    

    
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j>=w[i])f[j]+=f[j-w[i]];
        }
        
    }
    
    cout<<f[n];
    
    return 0;
}
