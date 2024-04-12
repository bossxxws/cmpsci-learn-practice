#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 11, M = 1 << N, C = N * N;

int n, m, K;
LL f[N][C][M];
int cnt[M];
vector<int> legal_state;
vector<int> state_trans[M];

bool check(int state)
{
    return !(state & state >> 1);
}
int count(int state)
{
    int res=0;
    while(state)
    {
        res++;
        state-=state & -state;
    }
    return res;
}
int main()
{
    cin >> n >> K;
    //Ԥ�������кϷ�״̬
    for (int st = 0; st < 1 << n; ++ st)
        //��鵱ǰ״̬�Ƿ�Ϸ�
        if (check(st))
            legal_state.push_back(st),
            cnt[st] = count(st);
    m = legal_state.size();
    //Ԥ�������кϷ�״̬�ĺϷ�ת��
    for (auto cur_st: legal_state)
        for (auto to_st: legal_state)
            if (!(cur_st & to_st) && check(cur_st | to_st))//���²�������������Ҳ������
                state_trans[cur_st].push_back(to_st);
    //��̬�滮
    f[0][0][0] = 1;
    for (int i = 1; i <= n; ++ i)
        for (int j = 0; j <= K; ++ j)
            for (auto &state: legal_state)
                for (auto &pre_st: state_trans[state])
                    if (j - cnt[state] >= 0)
                        f[i][j][state] += f[i - 1][j - cnt[state]][pre_st];
    //ͳ��Ŀ��״̬�����з�����
    LL res = 0;
    for (auto state: legal_state) res += f[n][K][state];
    cout << res << endl;
    return 0;
}

