#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y; cin>>x>>y;
    long long k = max(abs(x), abs(y));
    if(x >= y) cout<<4 * k * k + abs(x - k) + abs(y - k)<<endl;
    else cout<<4 * k * k - abs(x - k) - abs(y - k)<<endl;
    return 0;
}
