#include<iostream>

using namespace std;

const int N=100010;

int a[N];

//定义一个函数返回二进制数中最小的1
int lowbit(int x)
{
    return x&(~x+1);//~为按位取反
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;

        int res=0;
        while(x) x-=lowbit(x),res++;

        cout<<res<<' ';
    }
    return 0;
}
