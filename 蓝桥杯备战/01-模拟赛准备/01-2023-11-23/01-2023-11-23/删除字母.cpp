#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>

int main() {
    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    string result = "";

    int deleteCount = 0;	//标记当前所要删除的个数是否达标 

    for (int i = 0; i < n; i++) 
    {
        char c = str[i];	//将其取出来判断字典集大小 
        //cout << c; 

        //LANQIAO
        //AIAO
        while (deleteCount < m && result.length() > 0 && result[result.length() - 1] > c) {
            //当前所删除的未达标、结果集的长度大于0 且字符串的最后一位元素的字典集大于所取出来的 
            result.pop_back();
            deleteCount++;
        }

        result += c;	//将其加入结果字符串 
        //L 
        //A
        //AN
        //ANQ
        //AI
        //AIA
        //AIAO
    }

    //if (deleteCount < m)
    //{	//将后续所差的全部删去 
    //    int tmp = m - deleteCount;
    //    result.erase(result.length() - tmp, result.length());
    //}

    cout << result << endl;
    return 0;
}