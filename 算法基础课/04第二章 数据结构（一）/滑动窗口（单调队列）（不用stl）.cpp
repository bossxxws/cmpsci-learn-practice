#include<iostream>

using namespace std;

const int N=1e6+10;

int tt=-1,hh=0,dqu[N];

int n,k,a[N];

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    //for minnumber
    for(int i=0;i<n;i++)
    {
        while(tt>=hh && a[i]<dqu[tt])tt--;
        dqu[++tt]=a[i];
        if(i-k>=0&&dqu[hh]==a[i-k])hh++;
        if(i+1>=k)cout<<dqu[hh]<<" ";
    }
    cout<<endl;
    tt=-1;
    hh=0;
    for(int i=0;i<n;i++)
    {
        while(tt>=hh &&a[i]>dqu[tt])tt--;
        dqu[++tt]=a[i];
        if(i-k>=0 && dqu[hh]==a[i-k])hh++;
        if(i+1>=k)cout<<dqu[hh]<<" ";
    }
    return 0;
}
