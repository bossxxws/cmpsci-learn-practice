#include<iostream>
using namespace std;
const int N=1e7+10;
bool dp[N];
//dp[i]=true的话,说明组合成功;否则,组合失败
int main()
{
    int x1,x2;
    cin>>x1>>x2;
    dp[0]=true;
    dp[x1]=true;
    dp[x2]=true;
    for(int i=0;i<=10000000;i++)
    {
        if(i-x1>=0)
        dp[i]|=dp[i-x1];
        if(i-x2>=0)
        dp[i]|=dp[i-x2];
    }
    int ans;
    for(int i=0;i<=10000000;i++)
    if(!dp[i])
    ans=i;
    cout<<ans<<endl;
}

