#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
int main()
{
    int** pos = new int* [10];//分配一个行数为10的数组
    for (int i = 0; i < 10; ++i) {
        pos[i] = new int[1];//数组每行分配一个元素的空间
    }
    pos[9][0] = 10;
    cout << pos[9][0];

    // 释放动态分配的内存空间
    for (int i = 0; i < 10; ++i) {
        delete[] pos[i];
    }
    delete[] pos;

    return 0;
}