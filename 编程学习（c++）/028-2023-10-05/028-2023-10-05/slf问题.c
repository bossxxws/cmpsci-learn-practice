#include <stdio.h>

int main() {
    int age;
    float assets;
    char pet[30];

    printf("Enter your age, assets, and favorite pet.\n");

    scanf_s("%d %f", &age, &assets);
    scanf_s("%s", pet, sizeof(pet));

    printf("%d $%.2f %s\n", age, assets, pet);
  

    return 0;
}