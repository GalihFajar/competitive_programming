#include <iostream>
#include <cstring>

int main() {
    char date[50];
    char halloweenOne[10] = "OCT 31", halloweenTwo[10] = "DEC 25";
    int c, cnt = 0;

    while (c = getchar(), c != '\n') {
        date[cnt++] = c;
    }
    date[cnt] = '\0';

    if (strcmp(date, halloweenOne) == 0 || strcmp(date, halloweenTwo) == 0) {
        printf("yup\n");
    }
    else {
        printf("nope\n");
    }

    return 0;
}
