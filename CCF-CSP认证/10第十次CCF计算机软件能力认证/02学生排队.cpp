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
                if(a[i]==p){//�ҵ��������Ӧa[i],�ҵ�i��
                    t=i;
                    break;
                }
            }
            for(int i=t+1;i<=t+q;i++){
                a1[i-1]=a[i];//����
            }
            a1[t+q]=a[t];//����
        }
        else if(q<0){
            for(int i=1;i<=n;i++){
                if(a[i]==p){//�ҵ��������Ӧa[i],�ҵ�i��
                    t=i;
                    break;
                }
            }
            for(int i=t+q;i<=t-1;i++){
                a1[i+1]=a[i];//����
            }
            a1[t+q]=a[t];//����
        }
        for(int i=1;i<=n;i++){
            a[i]=a1[i];
        }//�洢һ��
    }
    for(int i=1;i<=n;i++){
            cout<<a1[i]<<' ';//��ӡ
         }

}



