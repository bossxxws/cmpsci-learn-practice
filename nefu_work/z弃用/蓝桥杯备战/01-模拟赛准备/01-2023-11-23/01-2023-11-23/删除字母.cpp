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

    int deleteCount = 0;	//��ǵ�ǰ��Ҫɾ���ĸ����Ƿ��� 

    for (int i = 0; i < n; i++) 
    {
        char c = str[i];	//����ȡ�����ж��ֵ伯��С 
        //cout << c; 

        //LANQIAO
        //AIAO
        while (deleteCount < m && result.length() > 0 && result[result.length() - 1] > c) {
            //��ǰ��ɾ����δ��ꡢ������ĳ��ȴ���0 ���ַ��������һλԪ�ص��ֵ伯������ȡ������ 
            result.pop_back();
            deleteCount++;
        }

        result += c;	//����������ַ��� 
        //L 
        //A
        //AN
        //ANQ
        //AI
        //AIA
        //AIAO
    }

    //if (deleteCount < m)
    //{	//�����������ȫ��ɾȥ 
    //    int tmp = m - deleteCount;
    //    result.erase(result.length() - tmp, result.length());
    //}

    cout << result << endl;
    return 0;
}