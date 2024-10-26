#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

string bar(int n) {
    char c = n + '0';
    string s(n, c);

    return s;
}

vector<string> wave(int n) {
    vector<string> out;

    for (int i = 1; i <= n; i++) {
        out.push_back(bar(i));
    }



    for (int i = n - 1; i >= 1; i--) {
        out.push_back(bar(i));
    }

    return out;
}

void print_wave(vector<string>& w) {
    for (string& s: w) {
        cout << s << '\n';
    }
}

void print_full_wave(int a, int f) {

    vector<string> w = wave(a);
    for (int i = 1; i <= f - 1; i++) {
        print_wave(w);
        cout << '\n';
    }

    print_wave(w);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    bool first = true;

    while (tc--) {
        int a, f;
        cin >> a >> f;

        if (!first) {
            cout << "\n";
        } else
            first = false;

        print_full_wave(a, f);
    }

    return 0;
}
