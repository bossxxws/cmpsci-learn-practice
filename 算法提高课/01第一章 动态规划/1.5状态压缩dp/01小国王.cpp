#include<bits/stdc++.h>

using namespace std;

typedef long long LL; 

//预处理出所有的合法状态、
 
//预处理出所有合法状态的合法转移（是一层一层转移的，从上一层转移过来的合法状态） 

//从上往下转移，我们只需考虑i-1层的状态

//f[i][j][k]表示第i层有j个小国王，并且状态为k （k是一个二进制数，1表示放，0表示没有放） 

//合法状态不多，合法转移状态更不多 
 
int n,m,K;

const int N=11;
const int M=N*N;
const int C=1<<N;//2的n次方 

int cnt[C];

LL f[N][M][C];

vector<int>legal_state;

vector<int>state_trans[C];

//任意王只要不相邻就是合法状态
bool check(int state)
{
	return !(state&state>>1);//&的运算优先级最低，>>其次 
} 

int count(int state)
{
	int res=0;
	while(state)
	{
		res++;
		state-=state & -state;//&的运算优先级最低，>>其次 
	}
	return res; 
}
 
int main()
{
	cin>>n>>K;
	
	//预处理所有合法状态 
	
	//只要不相邻就合法，从所有状态中枚举
	for(int i=0;i<1<<n;i++) 
	{
		if(check(i))
		{
			legal_state.push_back(i);
			//记录这种状态的放置个数
			cnt[i]=count(i); 	
		}
	}
	m = legal_state.size();
    //预处理所有合法状态的合法转移
    for (auto cur_st: legal_state)
        for (auto to_st: legal_state)
            if (!(cur_st & to_st) && check(cur_st | to_st))//上下不相邻且纵坐标也不相邻
                state_trans[cur_st].push_back(to_st);
    //动态规划
    f[0][0][0] = 1;
    for (int i = 1; i <= n; ++ i)
        for (int j = 0; j <= K; ++ j)
            for (auto &state: legal_state)
                for (auto &pre_st: state_trans[state])
                    if (j - cnt[state] >= 0)
                        f[i][j][state] += f[i - 1][j - cnt[state]][pre_st];
    //统计目标状态的所有方案数
    LL res = 0;
    for (auto state: legal_state) res += f[n][K][state];
    cout << res << endl;

	
	return 0;
} 
