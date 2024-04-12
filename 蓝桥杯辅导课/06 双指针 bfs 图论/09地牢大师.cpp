#include <bits/stdc++.h>
using namespace std;

const int N=110;

int l,r,c;  //�Թ�����
int px,py,pz,ex,ey,ez;  //piΪS��λ�ã�eiΪE��λ��

char mp[N][N][N];  //��¼�Թ�
int ans[N][N][N];  //�洢��
bool vis[N][N][N];  //��¼�õ��Ƿ��߹���״̬

struct point{  //�������
    int x,y,z;
};

queue<point> st;  //��������

int dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};  //ƫ��������

int bfs(){
    while(!st.empty()){  //����ͷ��Ϊ��ʱ����չ������ͷ
        auto p=st.front();
        for(int i=0;i<6;i++){
            int m_x=p.x+dx[i],m_y=p.y+dy[i],m_z=p.z+dz[i];  //ƫ��֮��ĵ������
            if(m_x<=l&&m_y<=r&&m_z<=c&&m_x>=1&&m_y>=1&&m_z>=1&&!vis[m_x][m_y][m_z]&&mp[m_x][m_y][m_z]!='#'){  //�ж�����
                vis[m_x][m_y][m_z]=1;  //���¸õ��߹���״̬
                ans[m_x][m_y][m_z]=ans[p.x][p.y][p.z]+1;  //����ƫ�ƺ�ĵ����S�Ĳ���
                if(mp[m_x][m_y][m_z]=='E') return  ans[m_x][m_y][m_z];  //�ѵ�Eֱ�ӷ��ش�
                st.push({m_x,m_y,m_z});  //���õ���ӣ�������չ����
            }
        }
        st.pop();  //��ͷ��չ������Ϻ����
    }
    return 0;  //���еĵ���չ�����������δ�����ѵ�E��˵���޽�
}

int main(){
    while(cin>>l>>r>>c&&l&&r&&c){  //��ʵ������
        //��ԭ����
        memset(ans,0,sizeof(ans)); 
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        while(st.size()){
            st.pop();
        }
        //�����Թ�
        for(int i=1;i<=l;i++){
            for(int j=1;j<=r;j++){
                for(int k=1;k<=c;k++){
                    cin>>mp[i][j][k];
                    if(mp[i][j][k]=='S') px=i,py=j,pz=k;  //
                    if(mp[i][j][k]=='E') ex=i,ey=j,ez=k;  //
                }
            }
        }

        vis[px][py][pz]=1;  //���S�Ѿ��߹�

        st.push({px,py,pz}); //S�����

        int cnt=bfs();  //��������������S�㿪ʼ����

        if(cnt!=0) printf("Escaped in %d minute(s).\n",cnt);
        else cout<<"Trapped!"<<endl;
    }

    return 0;
}
