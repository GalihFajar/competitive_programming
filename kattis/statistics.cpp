#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int cnt = 0;
    while (1) {
        int input;
        char dummy;
        int n, currMin = 1000000, currMax = -1000000;
        if (scanf("%d", &n) == EOF) break;

        while (n--) {
            scanf("%d", &input);
            currMin = min(currMin, input); currMax = max(currMax, input);
        }

        printf("Case %d: %d %d %d\n", ++cnt, currMin, currMax, currMax - currMin);
    }

    return 0;
}
