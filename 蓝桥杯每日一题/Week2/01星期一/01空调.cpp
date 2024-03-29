#include<bits/stdc++.h>

using namespace std;

const int N=1e5+3;

int n;

int a[N],b[N],c[N];

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)scanf("%d",&a[i]);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        a[i]=a[i]-b[i];
    }

    for(int i=n;i>0;i--)a[i]-=a[i-1];
    //注意差分要倒着求，因为正着求的时候a【i-1】已经改变

    //我们要让两个数组的差值归零，就是让两个数组的差值的差分数组归零
    //让差分数组全部归零的操作，肯定是差分数组中max（最大正数和，abs（最大负数和））

    int pos=0,neg=0;

    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)pos+=a[i];
        if(a[i]<0)neg-=a[i];//这里直接取相反的值，最后直接max比大小
    }

    cout<<max(pos,neg);

    return 0;
}


