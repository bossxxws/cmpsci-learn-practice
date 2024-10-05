#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 42;
double mat[N][N];
int n, m;
map<string, int> elei;
int index;

double eps = 1e-6;

void initMat()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = 0;
}

void getElement(string str, int &index, int in)
{
    str = str + '#';
    string ele = "";
    int num = 0;
    bool complete = false;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (c >= '0' && c <= '9')
        {
            complete = true;
            num = num * 10 + c - '0';
        }
        else
        {
            if (complete)
            {
                if (elei.find(ele) != elei.end())
                {
                    mat[elei[ele]][in] = num;
                }
                else
                {
                    elei[ele] = index++;
                    mat[elei[ele]][in] = num;
                }
                ele = c;
                num = 0;
                complete = false;
            }
            else
            {
                ele = ele + c;
            }
        }
    }
}

void _swap(int a, int b)
{
    double tmp;
    for (int i = 0; i < m; i++)
    {
        tmp = mat[a][i];
        mat[a][i] = mat[b][i];
        mat[b][i] = tmp;
    }
}

void _sub(int a, int b)
{
    double magni = mat[a][b] / mat[b][b];
    for (int i = b; i < m; i++)
    {
        mat[a][i] -= mat[b][i] * magni;
    }
}
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> m;
        string str;
        initMat();
        elei.clear();
        index = 0;

        for (int i = 0; i < m; i++)
        {
            cin >> str;
            getElement(str, index, i);
        }
        for (int i = 0; i < m; i++)
        {
            int j;
            for (j = i; j < index; j++)
                if (fabs(mat[j][i]) >= eps)
                    break;

            if (j == index)
                continue;
            else if (j != i)
            {
                _swap(i, j); // swap i j
            }

            for (j = i + 1; j < index; j++)
            {
                if (fabs(mat[j][i]) >= eps)
                {
                    _sub(j, i); // j line sub i
                }
            }
        }
        int k;
        for (k = 0; k < index && k < m; k++)
            if (fabs(mat[k][k]) <= eps)
                break;
        if (k < m)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
