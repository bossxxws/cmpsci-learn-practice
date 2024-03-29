#include<bits/stdc++.h>
using namespace std;
int n,f[13]={0,31,0,31,30,31,30,31,31,30,31,30,31},m;
int main(){
    cin>>n>>m;
    if(n%100!=0&&n%4==0||n%400==0)f[2]=29;
    else f[2]=28;
    int i=1;
    while(m>0){
        if(m-f[i]<=0)break;
        else {
            m-=f[i];
            i++;
        }
    }
    cout<<i<<"\n"<<m;
}

