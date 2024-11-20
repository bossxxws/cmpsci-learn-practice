#include<bits/stdc++.h>
using namespace std;
int a[1005];
int a1[1005];
int p,q;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i]=i;
        a1[i]=i;
    }
    while(m--){
        cin>>p>>q;
        int t=0;
        if(q>0){
            for(int i=1;i<=n;i++){
                if(a[i]==p){//找到这个数对应a[i],找到i；
                    t=i;
                    break;
                }
            }
            for(int i=t+1;i<=t+q;i++){
                a1[i-1]=a[i];//交换
            }
            a1[t+q]=a[t];//交换
        }
        else if(q<0){
            for(int i=1;i<=n;i++){
                if(a[i]==p){//找到这个数对应a[i],找到i；
                    t=i;
                    break;
                }
            }
            for(int i=t+q;i<=t-1;i++){
                a1[i+1]=a[i];//交换
            }
            a1[t+q]=a[t];//交换
        }
        for(int i=1;i<=n;i++){
            a[i]=a1[i];
        }//存储一下
    }
    for(int i=1;i<=n;i++){
            cout<<a1[i]<<' ';//打印
         }

}



