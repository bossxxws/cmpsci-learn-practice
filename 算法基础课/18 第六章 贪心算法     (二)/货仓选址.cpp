//|a-x| + |b-x| >= |(a-x)+(x-b)| (����ֵ����ʽ)
//��|a-x| + |b-x| >= |a-b|
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;
int a[N];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    
    sort(a,a+n);
    
    int res=0;
    
    for(int i=0;i<n;i++)
    {
        res+=abs(a[i]-a[n/2]);//n/2����λ��
    }
    
    cout<<res<<endl;
    
    return 0;
}
