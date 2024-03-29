//博弈论

//ICG游戏

/*
若一个游戏满足：
1、两名玩家交替行动
2、游戏进程的任意时刻，可以执行的合法行动与轮到哪名玩家无关
3、不能行动的玩家判负
则称该游戏为一个公平组合游戏
常见的棋类游戏，比如围棋就不是公平组合游戏。因为围棋交战双方分别只能落白子和黑子，胜负判定也比较复杂
*/


//把所有石堆异或，如果是0，先手必败
//不是0，先手必胜

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int res=0;
    
    int n;
    cin>>n;
    
    while(n--)
    {
        int a;
        cin>>a;
        
        res^=a;
        
    }
    
    if(res)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
