#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

int mod(int a, int b) {
    return (a % b + b) % b;
}

char translate(int c, int n) {
    if (!(c - 'a' >= 0 && c - 'a' <= 25) && !(c - 'A' >= 0 && c - 'A' <= 25))
        return c;

    bool isUpper = (c - 'A' >= 0 && c - 'A' <= 25);

    c = tolower(c);
    c = c + n;

    if (c - 'a' >= 26 || c < 'a') {
        c = mod(c - 'a', 26);
        c = c + 'a';
    }

    if (isUpper) c = toupper(c);
    return c;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        string n;
        string s;
        getline(cin, n);
        int n_ = stoi(n);
        if (cin.eof() || n_ == 0)
            return 0;

        getline(cin, s);

        for (char c: s) {
            cout << translate(c, n_);
        }
        cout << endl;
    }

    return 0;
}
