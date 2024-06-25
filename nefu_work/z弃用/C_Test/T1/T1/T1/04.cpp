#include <stdio.h>

void mess(int* a, int b) {
    int t;
    t = *a;
    *a = b;
    b = t;
}

int main(void) {
    int x, y;
    x = 4;
    y = 5;
    mess(&x, y);
    printf("x = %d, y = %d\n", x, y);

    return 0;
}