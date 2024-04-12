#include <bits/stdc++.h>
using namespace std;

const int N=110;

int l,r,c;  //迷宫参数
int px,py,pz,ex,ey,ez;  //pi为S的位置，ei为E的位置

char mp[N][N][N];  //记录迷宫
int ans[N][N][N];  //存储答案
bool vis[N][N][N];  //记录该点是否走过的状态

struct point{  //点的坐标
    int x,y,z;
};

queue<point> st;  //搜索队列

int dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};  //偏移量数组

int bfs(){
    while(!st.empty()){  //当队头不为空时，扩展搜索队头
        auto p=st.front();
        for(int i=0;i<6;i++){
            int m_x=p.x+dx[i],m_y=p.y+dy[i],m_z=p.z+dz[i];  //偏移之后的点的坐标
            if(m_x<=l&&m_y<=r&&m_z<=c&&m_x>=1&&m_y>=1&&m_z>=1&&!vis[m_x][m_y][m_z]&&mp[m_x][m_y][m_z]!='#'){  //判断条件
                vis[m_x][m_y][m_z]=1;  //更新该点走过的状态
                ans[m_x][m_y][m_z]=ans[p.x][p.y][p.z]+1;  //更新偏移后的点距离S的步骤
                if(mp[m_x][m_y][m_z]=='E') return  ans[m_x][m_y][m_z];  //搜到E直接返回答案
                st.push({m_x,m_y,m_z});  //将该点入队，继续扩展搜索
            }
        }
        st.pop();  //队头扩展搜索完毕后出队
    }
    return 0;  //所有的点扩展搜索完后若还未返回搜到E，说明无解
}

int main(){
    while(cin>>l>>r>>c&&l&&r&&c){  //多实例读入
        //还原数据
        memset(ans,0,sizeof(ans)); 
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        while(st.size()){
            st.pop();
        }
        //读入迷宫
        for(int i=1;i<=l;i++){
            for(int j=1;j<=r;j++){
                for(int k=1;k<=c;k++){
                    cin>>mp[i][j][k];
                    if(mp[i][j][k]=='S') px=i,py=j,pz=k;  //
                    if(mp[i][j][k]=='E') ex=i,ey=j,ez=k;  //
                }
            }
        }

        vis[px][py][pz]=1;  //标记S已经走过

        st.push({px,py,pz}); //S点入队

        int cnt=bfs();  //调用搜索，将从S点开始搜索

        if(cnt!=0) printf("Escaped in %d minute(s).\n",cnt);
        else cout<<"Trapped!"<<endl;
    }

    return 0;
}
