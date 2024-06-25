#include<bits/stdc++.h>

using namespace std;

const int N = 4e5;

struct node
{
    int time, nation;
};

int n;//到达船只 
int m, k;//到达时间m，到达人数k 

int ans;

node q[N];
int hh = 0, tt = -1;;//结构体队列 

int nation[N];//记录国籍 

int main()
{
    scanf("%d", &n);
    

    while (n -- )
    {
        scanf("%d%d", &m, &k);
        
        while (hh <= tt)
        {
            node t = q[hh];
            
            if (m - t.time >= 86400)
            {
                nation[t.nation] -- ;
                if (nation[t.nation] == 0) ans -- ;
                
                hh ++ ;
                continue;
            }
            
            break;
        }
        
        for (int i = 1; i <= k; i ++ )
        {
            int d;
            scanf("%d", &d);
            
            q[++tt] = {m, d};
            nation[d] ++ ;
            
            if (nation[d] == 1) ans ++ ;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
