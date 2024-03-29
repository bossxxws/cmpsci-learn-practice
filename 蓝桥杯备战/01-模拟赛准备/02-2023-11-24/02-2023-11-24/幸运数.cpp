#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
/*

小蓝认为如果一个数含有偶数个数位，并且前面一半的数位之和等于后面一半的数位之和，则这个数是他的幸运数字。
例如 2314 是一个幸运数字，因为它有 4 个数位，并且 2 + 3 = 1 + 4 。
现在请你帮他计算从 1 至 100000000 之间共有多少个不同的幸运数字。
本题的结果为一个整数，在提交答案时只输出这个整数，输出多余的内容将无法得分。

*/
int getSumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countLuckyNumbers(int start, int end) {
    int count = 0;
    for (int num = start; num <= end; ++num) {
        int digits = 0;
        int temp = num;
        while (temp > 0) {
            temp /= 10;
            digits++;
        }

        if (digits % 2 == 0) {
            int firstHalf = 0;
            int secondHalf = 0;

            temp = num;
            for (int i = 0; i < digits / 2; ++i) {
                secondHalf += temp % 10;
                temp /= 10;
            }
            for (int i = 0; i < digits / 2; ++i) {
                firstHalf += temp % 10;
                temp /= 10;
            }

            if (firstHalf == secondHalf) {
                count++;
            }
        }
    }
    return count;
}
/*
4430091
*/
int main() {
    int start = 1;
    int end = 100000000;
    int count = countLuckyNumbers(start, end);
    cout << "The number of distinct lucky numbers between " << start << " and " << end << " is: " << count << endl;
    int l = 022;
    cout << (l != 0);
    return 0;
}