#include<iostream>

using namespace std;

const int N=100010;

int a[N],q[N];

int res;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0,j=0;i<n;i++)
    {
        q[a[i]]++;
        while(q[a[i]]>1)
        {
            q[a[j]]--;
            j++;
        }
        res=max(res,i-j+1);
    }
    cout<<res;
	return 0;
}
