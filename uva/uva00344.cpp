#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<string, int> psi;

vector<psi> roman_chars = {
    {"c", 100},
    {"xc", 90},
    {"l", 50},
    {"xl", 40},
    {"x", 10},
    {"ix", 9},
    {"v", 5},
    {"iv", 4},
    {"i", 1}
};


string convert(int x) {
    string out = "";

    while (x > 0) {
        for (auto r: roman_chars) {
            if (x - r.second >= 0) {
                out += r.first;
                x -= r.second;
                break;
            }
        }
    }

    return out;
}

void calculate(string& roman, unordered_map<char, int>& count_chars) {

    for (char c: roman) {
        count_chars[c]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int input;
        cin >> input;
        if (input == 0 || cin.eof()) {
            return 0;
        }

        unordered_map<char, int> count_chars = {
            {'i', 0},
            {'v', 0},
            {'x', 0},
            {'l', 0},
            {'c', 0}
        };

        for (int i = 0; i <= input; i++) {
            string temp = convert(i);
            calculate(temp, count_chars);
        }

        cout << input << ":";
        cout << " " << count_chars['i'] << " " << "i,";
        cout << " " << count_chars['v'] << " " << "v,";
        cout << " " << count_chars['x'] << " " << "x,";
        cout << " " << count_chars['l'] << " " << "l,";
        cout << " " << count_chars['c'] << " " << "c\n";
    }

    return 0;
}
