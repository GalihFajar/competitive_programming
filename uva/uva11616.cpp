#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<string, int> psi;

vector<psi> r_ar_pair = {
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

unordered_map<char, bool> r_preceed = {
    {'I', true},
    {'X', true},
    {'C', true},
    {'V', true}
};

string convert(int x) {
    string out = "";

    while (x > 0) {
        for (psi& p: r_ar_pair) {
            if (x - p.second >= 0) {
                out += p.first;
                x -= p.second;
                break;
            }
        }
    }

    return out;
}

int get_ar_from_r(string& s) {
    for (psi& p: r_ar_pair) {
        if (p.first == s)
            return p.second;
    }

    return -1;
}

int to_arabic(string& x) {

    int out = 0;
    int i = 0;
    while (i < (int) x.size()) {
        if (r_preceed[x[i]] && i + 1 < (int) x.size()) {
            string s = ""; s += x[i]; s += x[i + 1];
            int temp = get_ar_from_r(s);
            if (temp != -1) {
                out += temp;
                i += 2;
                continue;
            }
        }

        string s = ""; s += x[i];
        out += get_ar_from_r(s);
        i++;
    }

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (1) {
        string s;
        cin >> s; if (cin.eof()) return 0;

        if (s[0] - '0' >= 0 && s[0] - '0' <= 9) {
            cout << convert(stoi(s)) << '\n';
        } else {
            cout << to_arabic(s) << '\n';
        }
    }

    return 0;
}
