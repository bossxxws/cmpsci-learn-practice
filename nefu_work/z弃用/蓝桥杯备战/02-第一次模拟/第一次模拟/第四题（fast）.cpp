#include <iostream>
#include <vector>

using namespace std;

int countDivisors(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<vector<int>> numbers = {
        {393353, 901440, 123481, 850930, 423154, 240461},
        {373746, 232926, 396677, 486579, 744860, 468782},
        {941389, 777714, 992588, 343292, 385198, 876426},
        {483857, 241899, 544851, 647930, 772403, 109929},
        {882745, 372491, 877710, 340000, 659788, 658675},
        {296521, 491295, 609764, 718967, 842000, 670302}
    };

    int maxDivisors = 0;
    int maxDivisorsNumber = 0;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers[i].size(); j++) {
            int divisors = countDivisors(numbers[i][j]);
            if (divisors > maxDivisors) {
                maxDivisors = divisors;
                maxDivisorsNumber = numbers[i][j];
            }
        }
    }

    cout << "约数个数最多的数是: " << maxDivisorsNumber << endl;

    return 0;
}