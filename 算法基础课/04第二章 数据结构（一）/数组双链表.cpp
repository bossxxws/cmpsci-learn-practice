#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int m;
int e[N], l[N], r[N];
int idx;

//! ��ʼ��
void init()
{
    l[1] = 0, r[0] = 1;//* ��ʼ�� ��һ������ұ��� 1   �ڶ����������� 0
    idx = 2;//! idx ��ʱ�Ѿ��õ���������
}

//* �ڵ� K �����ұ߲���һ�� X 
void add(int k, int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k]; //todo ��ߵ� k ���� 1 �� �����ʱ�� k+1 �ͺ�
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}//! ��Ȼ�� K ����߲���һ���� ������дһ�� �� Ҳ����ֱ�ӵ������������������ k ����߲���һ�� �� �ȼ����� l[k] ���ұ߲���һ���� add(l[k],x)

//*ɾ���� k�� ��
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}



int main(void)
{
    ios::sync_with_stdio(false);
    cin >> m;

    init();

    while(m--)
    {
        string op;
        cin >> op;
        int k, x;
        if(op=="R")
        {
            cin >> x;
            add(l[1], x); //!   0�� 1 ֻ�Ǵ��� ͷ��β  ����   ���ұ߲��� ֻҪ��  ָ�� 1�� �Ǹ�����ұ߲���Ϳ�����
        }
        else if(op=="L")//! ͬ��  ����߲������ ��ָ�� 0��������߲���Ϳ�����   Ҳ���ǿ���ֱ���� 0�� ���ұ߲���
        {
            cin >> x;
            add(0, x);
        }
        else if(op=="D")
        {
            cin >> k;
            remove(k + 1);
        }
        else if(op=="IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            add(k + 1, x);
        }    
    }
    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';

    return 0;
}

