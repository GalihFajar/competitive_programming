#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<string, int> psi;

vector<psi> roman_ar_map = {
    {"M", 1000},
    {"CM", 900},
    {"D", 500},
    {"CD", 400},
    {"C", 100},
    {"XC", 90},
    {"L", 50},
    {"XL", 40},
    {"X", 10},
    {"IX", 9},
    {"V", 5},
    {"IV", 4},
    {"I", 1}
};

unordered_map<char, int> roman_sticks = {
    {'I', 1},
    {'V', 2},
    {'X', 2},
    {'L', 2},
    {'C', 2},
    {'D', 3},
    {'M', 4}
};

string convert(int x) {
    string out = "";

    while (x > 0) {
        for (psi& p: roman_ar_map) {
            if (x - p.second >= 0) {
                out += p.first;
                x -= p.second;
                break;
            }
        }
    }

    return out;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int in;
        cin >> in; if (cin.eof()) return 0;

        auto count = [&] (string& s) -> int {
            int out = 0;

            for (char c: s) {
                out += roman_sticks[c];
            }

            return out;
        };

        string roman = convert(in);

        cout << count(roman) << endl;
    }

    return 0;
}
