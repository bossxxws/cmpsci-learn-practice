#include<iostream>

using namespace std;

const int N=100010;

int a[N];

//����һ���������ض�����������С��1
int lowbit(int x)
{
    return x&(~x+1);//~Ϊ��λȡ��
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
