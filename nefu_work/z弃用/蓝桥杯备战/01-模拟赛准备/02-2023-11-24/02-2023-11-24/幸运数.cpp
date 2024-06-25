#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
/*

С����Ϊ���һ��������ż������λ������ǰ��һ�����λ֮�͵��ں���һ�����λ֮�ͣ���������������������֡�
���� 2314 ��һ���������֣���Ϊ���� 4 ����λ������ 2 + 3 = 1 + 4 ��
���������������� 1 �� 100000000 ֮�乲�ж��ٸ���ͬ���������֡�
����Ľ��Ϊһ�����������ύ��ʱֻ�����������������������ݽ��޷��÷֡�

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