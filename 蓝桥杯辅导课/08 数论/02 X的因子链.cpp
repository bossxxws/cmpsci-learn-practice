#include <iostream>

using namespace std;

const int N = 20;

int alpha[N], idx;

// ������� C(a, b)
long long comb(int a, int b) {
    long long nume = 1, deno = 1;
    for (int i = 0; i < b; i++) {
        nume *= a - i;      // ���� = a(a-1)..(a-b+1)
        deno *= i + 1;      // ��ĸ = b(b-1)..1
    }

    return nume / deno;
}

void process(int x) {
    if (x == 1) {
        cout << "0 0" << '\n';
        return;
    }

    // �Գ����ֽ�������, �õ��������� prime_i ��ָ�� alpha_i
    idx = 0;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            alpha[idx] = 0; 
            while (x % i == 0) {
                alpha[idx]++;
                x /= i;
            }
            idx++;
        }
    }

    if (x > 1) {
        alpha[idx++] = 1;
    }

    // ���������ù�ʽ (*) �� (**) ���
    int len = 0;
    long long num = 1;
    for (int i = 0; i < idx; i++) {
        len += alpha[i];
        num *= comb(len, alpha[i]);
    }

    cout << len << ' ' << num << '\n';
}

int main() {


    int x;
    while (cin >> x) {
        process(x);
    }

    return 0;
}

