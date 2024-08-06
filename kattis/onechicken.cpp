#include <iostream>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    if (a > b) {
        printf("Dr. Chaz needs %d more %s of chicken!\n", (a - b), (a - b) == 1 ? "piece" : "pieces");
    } else {
        printf("Dr. Chaz will have %d %s of chicken left over!\n", (b - a), (b - a) == 1 ? "piece" : "pieces");
    }

    return 0;
}
