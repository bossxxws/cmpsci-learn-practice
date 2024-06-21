#include<bits/stdc++.h>

using namespace std;

typedef long long LL; 

//Ԥ��������еĺϷ�״̬��
 
//Ԥ��������кϷ�״̬�ĺϷ�ת�ƣ���һ��һ��ת�Ƶģ�����һ��ת�ƹ����ĺϷ�״̬�� 

//��������ת�ƣ�����ֻ�迼��i-1���״̬

//f[i][j][k]��ʾ��i����j��С����������״̬Ϊk ��k��һ������������1��ʾ�ţ�0��ʾû�зţ� 

//�Ϸ�״̬���࣬�Ϸ�ת��״̬������ 
 
int n,m,K;

const int N=11;
const int M=N*N;
const int C=1<<N;//2��n�η� 

int cnt[C];

LL f[N][M][C];

vector<int>legal_state;

vector<int>state_trans[C];

//������ֻҪ�����ھ��ǺϷ�״̬
bool check(int state)
{
	return !(state&state>>1);//&���������ȼ���ͣ�>>��� 
} 

int count(int state)
{
	int res=0;
	while(state)
	{
		res++;
		state-=state & -state;//&���������ȼ���ͣ�>>��� 
	}
	return res; 
}
 
int main()
{
	cin>>n>>K;
	
	//Ԥ�������кϷ�״̬ 
	
	//ֻҪ�����ھͺϷ���������״̬��ö��
	for(int i=0;i<1<<n;i++) 
	{
		if(check(i))
		{
			legal_state.push_back(i);
			//��¼����״̬�ķ��ø���
			cnt[i]=count(i); 	
		}
	}
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
