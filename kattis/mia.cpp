#include <iostream>

bool isMia(int&, int&);
bool isDouble(int&, int&);
int result(int, int);
bool printTie();
bool printPlayer1();
bool printPlayer2();

int main() {

    while (1) {
        int s0, s1, t0, t1;

        scanf("%d %d %d %d", &s0, &s1, &t0, &t1);
        if (s0 == 0 && s1 == 0 && t0 == 0 && t1 == 0) {
            return 0;
        }

        // check mia
        if (isMia(s0, s1) && isMia(t0, t1) && printTie()) continue;
        else if (isMia(s0, s1) && !isMia(t0, t1) && printPlayer1()) continue;
        else if (isMia(t0, t1) && !isMia(s0, s1) && printPlayer2()) continue;

        // check double
        if (isDouble(s0, s1) && isDouble(t0, t1) && s0 == t0 && printTie()) continue;
        else if (isDouble(s0, s1) && !isDouble(t0, t1) && printPlayer1()) continue;
        else if (isDouble(t0, t1) && !isDouble(s0, s1) && printPlayer2()) continue;

        // checkresult
        if (result(s0, s1) > result(t0, t1) && printPlayer1()) continue;
        else if (result(t0, t1) > result(s0, s1) && printPlayer2()) continue;
        else printTie();
    }

    return -1;
}

bool isMia(int &a, int &b) {
    if ((a == 1 && b == 2) || (a == 2 && b == 1)) return true;

    return false;
}

bool isDouble(int &a, int &b) {
    if (a == b) return true;
    return false;
}

int result(int a, int b) {
    if (a > b) return a * 10 + b;
    else if (b > 0) return b * 10 + a;

    return -1;
}

bool printTie() {
    printf("Tie.\n");
    return true;
}

bool printPlayer1() {
    printf("Player 1 wins.\n");
    return true;
}

bool printPlayer2() {
    printf("Player 2 wins.\n");
    return true;
}
