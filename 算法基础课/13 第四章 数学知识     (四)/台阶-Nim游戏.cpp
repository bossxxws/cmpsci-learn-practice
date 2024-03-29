//奇数台阶异或，如果不是0，则先手必胜

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int res=0;
    
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        
        if(i%2)res^=x;
    }
    
    if(res)puts("Yes");
    else puts("No");
    
    return 0;
    
    
    return 0;
}
