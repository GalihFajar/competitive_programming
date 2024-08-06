#include <iostream>
using namespace std;

int main() {
    char s[50];
    int cnt = 0;
    int t;
    // fgets(s, 50, stdin);
    while (t = getchar(), t != '\n') {
        s[cnt++] = (char) t;
    }
    s[cnt++] = '\0';

    printf("Thank you, %s, and farewell!\n", s);
}
