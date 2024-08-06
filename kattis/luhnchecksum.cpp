#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

int transform(int n) {
    n = n * 2;

    if (n >= 10) {
        n = (n / 10) + (n % 10);
    }

    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        string input;
        cin >> input;
        int out = 0;

        for (int i = (int) input.size() - 2; i >= 0; i -= 2) {
            out += transform(input[i] - '0');
        }

        for (int i = (int) input.size() - 1; i >= 0; i -= 2) {
            out += input[i] - '0';
        }


        bool valid = out % 10 == 0;

        if (valid)
            cout << "PASS\n";
        else
            cout << "FAIL\n";
    }

    return 0;
}
