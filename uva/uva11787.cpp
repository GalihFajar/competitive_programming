#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<char, int> glyph_map = {
    {'B', 1},
    {'U', 10},
    {'S', 100},
    {'P', 1000},
    {'F', 10000},
    {'T', 100000},
    {'M', 1000000},
};

int convert(string& s) {
    int last_processed = 0;
    int out = 0;
    unordered_map<char, int> glyph_usage;

    for (int i = 0; i < (int) s.size(); i++) {
        int num = glyph_map[s[i]];
        if (num < last_processed)
            return -1;
        out += num;
        last_processed = num;

        glyph_usage[s[i]]++;
        if (glyph_usage[s[i]] > 9)
            return -1;
    }

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; if (cin.eof()) return 0;

    while (tc--) {
        string s;
        cin >> s;

        int out_1, out_2;
        out_1 = convert(s);
        reverse(s.begin(), s.end());
        out_2 = convert(s);

        if (out_1 != -1) {
            cout << out_1 << '\n';
        } else if (out_2 != -1) {
            cout << out_2 << '\n';
        } else {
            cout << "error" << '\n';
        }
    }

    return 0;
}
