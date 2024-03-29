/*
������֪��QWQ�������Ǽ�̽�պ����У�һ����������K�ǣ���������������һλ���ص����ˣ���λ����������n�����ÿ�����ﶼ��һ���ļ۸�����ֵ�����QWQ����������й������ֻ�ܻ���������Ψһ��ͨ���������㱦ʯ��������K���Ϲ��ڹ���������ֵĹ涨:

�������������㱦ʯ������������ڻ��ߵ�����Ҫ������ļ۸�
ÿ�����һ�����ף��������������㱦ʯ�������ͻ���������ı���ļ۸񣬲��۹�����ԭ���ж��ٸ����㱦ʯ��

���ڣ�QWQ������k�����㱦ʯ��������뻻ȡ�������ֵ�����ֵ�Ƕ����أ�
Input
ÿ������������
��һ�� ��������n����ʼ��ʯ����k
�ڶ��� ÿһ������ļ۸�
������ ÿ����������ֵ

1 <= n <= 100000
���������������100
Output
����������ֵ
Sample Input
5 6
2 4 6 8 10
1 50 10 2 50
Sample Output
61
*/
#include<bits/stdc++.h>

using namespace std;

struct Treasure {
    int price;
    int value;
};

bool compareByPrice(const Treasure& t1, const Treasure& t2) {
    return t1.price < t2.price;
}

int getMaxTreasureValue(int n, int k, vector<Treasure>& treasures) {
    sort(treasures.begin(), treasures.end(), compareByPrice);

    int maxTreasureValue = 0;
    for (int i = 0; i < n; i++) {
        if (treasures[i].price <= k) {
            maxTreasureValue += treasures[i].value;
        }
    }

    return maxTreasureValue;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Treasure> treasures(n);
    for (int i = 0; i < n; i++) {
        cin >> treasures[i].price;
    }

    for (int i = 0; i < n; i++) {
        cin >> treasures[i].value;
    }

    int maxTreasureValue = getMaxTreasureValue(n, k, treasures);
    cout << maxTreasureValue << endl;

    return 0;
}
