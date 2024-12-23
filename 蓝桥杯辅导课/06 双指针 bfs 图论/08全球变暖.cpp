#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define x first
#define y second
using namespace std;
char arr[1010][1010];
bool finddao[1010][1010];
int N;
bool bfs(pair<int,int>s1){
    int sum=0;//计算不被海水侵蚀的路地块个数
    bool mark;//用于判断是否被侵蚀
    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};//初始化偏移量
    queue<pair<int,int>>dui;
    dui.push(s1);
    while(dui.size()){
        auto s2=dui.front();
        dui.pop();
        mark=1;
        for(int i=0;i<4;i++){
            int x1=s2.x+dx[i],y1=s2.y+dy[i];
            if(x1<0||x1>=N||y1<0||y1>=N)continue;
            if(arr[x1][y1]=='.'){mark=0;continue;}
            if(finddao[x1][y1])continue;
                finddao[x1][y1]=true;
                dui.push(make_pair(x1,y1));
        }
        if(mark==1)sum++;
    }
    if(sum>=1)
    return 1;
    else 
    return 0;
}
int main(){
    int allisland=0,lifeisland=0;
    pair<int,int> s1;
    cin>>N;
    for(int i=0;i<N;i++)cin>>arr[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]=='#'&&!finddao[i][j]){
                s1={i,j};
                allisland++;
                lifeisland+=bfs(s1);
            }
        }
    }
    cout<<allisland-lifeisland;
    return 0;
}
