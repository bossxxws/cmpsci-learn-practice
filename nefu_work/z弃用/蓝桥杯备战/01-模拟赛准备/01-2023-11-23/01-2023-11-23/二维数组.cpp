#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
int main()
{
    int** pos = new int* [10];//����һ������Ϊ10������
    for (int i = 0; i < 10; ++i) {
        pos[i] = new int[1];//����ÿ�з���һ��Ԫ�صĿռ�
    }
    pos[9][0] = 10;
    cout << pos[9][0];

    // �ͷŶ�̬������ڴ�ռ�
    for (int i = 0; i < 10; ++i) {
        delete[] pos[i];
    }
    delete[] pos;

    return 0;
}