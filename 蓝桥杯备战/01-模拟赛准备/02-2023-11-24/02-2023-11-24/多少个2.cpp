#include <iostream>

int countOccurrencesOfTwo(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 10 == 2) {
            count++;
        }
        num /= 10;
    }
    return count;
}

int main() {
    int totalCount = 0;
    for (int i = 1; i <= 2020; i++) {
        totalCount += countOccurrencesOfTwo(i);
    }

    std::cout << "Total count of occurrences of 2: " << totalCount << std::endl;

    return 0;
}