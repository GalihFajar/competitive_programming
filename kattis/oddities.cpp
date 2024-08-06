#include <stdio.h>

int main() {
    short TC;

    scanf("%hd", &TC);

    while (TC--) {
        int t;
        scanf("%d", &t);
        printf("%d is %s\n", t, t % 2 == 0 ? "even" : "odd");
    }

    return 0;
}
