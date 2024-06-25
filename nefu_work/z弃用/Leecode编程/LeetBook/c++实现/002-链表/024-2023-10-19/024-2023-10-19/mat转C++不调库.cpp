#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> gaussElimination(const std::vector<std::vector<double>>& A, const std::vector<double>& B) {
    // 实现高斯消元法求解线性方程组
    // ...
}

int main() {
    int n;
    std::cout << "请输入 n 的值: ";
    std::cin >> n;

    double x = n * n;

    std::vector<std::vector<double>> A(n, std::vector<double>(n, 0.0));
    A[0][0] = 3 * x + 1;
    A[0][1] = -x;
    A[n - 1][n - 2] = -x;
    A[n - 1][n - 1] = x + 1;

    for (int i = 1; i < n - 1; i++) {
        A[i][i - 1] = -x;
        A[i][i] = 2 * x + 1;
        A[i][i + 1] = -x;
    }

    std::vector<double> B(n, 0.0);
    for (int j = 0; j < n - 1; j++) {
        B[j] = 0;
    }
    B[n - 1] = n;

    std::vector<double> q1 = gaussElimination(A, B);

    std::vector<double> p1;
    for (int i = 0; i < n; i++) {
        p1.push_back(0.5 / n + (double)i / n);
    }

    std::vector<double> p2;
    std::vector<double> q2;
    for (double p = 0; p <= 1.0; p += 0.01) {
        p2.push_back(p);
        q2.push_back(exp(1) * (exp(p) - exp(-p)) / (exp(1) * exp(1) + 1));
    }

    // 输出结果
    std::cout << "p1: ";
    for (const auto& p : p1) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    std::cout << "q1: ";
    for (const auto& q : q1) {
        std::cout << q << " ";
    }
    std::cout << std::endl;

    std::cout << "p2: ";
    for (const auto& p : p2) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    std::cout << "q2: ";
    for (const auto& q : q2) {
        std::cout << q << " ";
    }
    std::cout << std::endl;

    return 0;
}
int main()
{

	system("pause");

	return 0;
}