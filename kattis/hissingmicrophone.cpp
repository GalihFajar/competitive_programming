#include <iostream>
using namespace std;

int main() {
    char input[31];
    int curr;
    int cnt = 0;

    while (curr = getchar(), curr != '\n') {
        input[cnt++] = curr;
    }

    input[cnt] = '\0';

    int sCount;

    for (int i = 0; i < cnt; i++) {
        if (input[i] == 's' && i + 1 < cnt && input[i + 1] == 's') {
            printf("hiss\n");
            return 0;
        }
    }

    printf("no hiss\n");
    return 0;
}
