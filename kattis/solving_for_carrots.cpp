#include <iostream>
#include <string>
using namespace std;

int main() {
    int TC, out;
    string s;
    scanf("%d %d", &TC, &out);

    int c;
    while (TC--) {
        do {
            c = getchar();
        } while (c != '\n');
    }

    printf("%d\n", out);

    return 0;
}
