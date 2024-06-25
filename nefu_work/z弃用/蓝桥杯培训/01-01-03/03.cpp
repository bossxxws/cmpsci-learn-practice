/*
众所周知，QWQ热衷于星际探险和旅行，一天他来到了K星，在这里他遇到了一位神秘的商人，这位商人手中有n个宝物，每个宝物都有一定的价格和珍藏值。如果QWQ想从商人手中购买宝物，就只能花费宇宙中唯一的通货——永恒宝石，但是在K星上关于购买宝物有奇怪的规定:

购买者手中永恒宝石的数量必须大于或者等于想要购买宝物的价格；
每当完成一个交易，购买者手中永恒宝石的数量就会变成所购买的宝物的价格，不论购买者原来有多少个永恒宝石；

现在，QWQ手中有k个永恒宝石，如果他想换取最大的珍藏值，这个值是多少呢？
Input
每组输入有三行
第一行 宝物数量n，初始宝石数量k
第二行 每一个宝物的价格
第三行 每个宝物的珍藏值

1 <= n <= 100000
其余输入均不大于100
Output
输出最大的珍藏值
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
