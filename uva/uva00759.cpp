#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<char, int> rn_to_ar_map {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
};

unordered_map<char, int> ar_ro_rn_map {
    {1000, 'M'},
    {500, 'D'},
    {100, 'C'},
    {50, 'L'},
    {10, 'X'},
    {5, 'V'},
    {1, 'I'}
};

unordered_map<char, bool> digraph_allowed = {
    {'I', true},
    {'X', true},
    {'C', true}
};

unordered_map<string, int> digraph = {
    {"IV", 4},
    {"IX", 9},
    {"XL", 40},
    {"XC", 90},
    {"CD", 400},
    {"CM", 900}
};

vector<string> roman_list_ordered = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

pair<int, string> solve_numeral(int& current_idx, string& s) {
    string s_ = "";
    if (digraph_allowed.count(s[current_idx]) && current_idx < (int) s.size() - 1) {
        s_ += s[current_idx];
        s_ += s[current_idx + 1];
        if (digraph.count(s_)) {
            current_idx += 2;
            return {digraph[s_], s_};
        }
    }
    s_ += s[current_idx];

    return {rn_to_ar_map[s[current_idx++]], s_};
}

int rn_to_ar_naive(string& s) {
    int ret = 0;
    string last_processed = "";
    int i = 0;

    while (i < (int) s.length()) {
        ret += solve_numeral(i,s).first;
    }

    return ret;
}

string ar_to_rn(int in) {
    string ret = "";
    while (in > 0) {
        for (int i = 0; i < roman_list_ordered.size(); i++) {
            string temp = roman_list_ordered[i];
            int current = 0;
            if (temp.size() == 1)
                current = rn_to_ar_map[temp[0]];
            else
                current = digraph[temp];

            if (in - current >= 0) {
                in -= current;
                ret += temp;
                break;
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (1) {
        string in;
        cin >> in;
        if (cin.eof()) return 0;

        int potential_ar = rn_to_ar_naive(in);
        if (potential_ar >= 4000 || potential_ar <= 0) {
            cout << "This is not a valid number" << endl;
            continue;
        }

        if (in == ar_to_rn(potential_ar))
            cout << potential_ar << endl;
        else
            cout << "This is not a valid number" << endl;
    }

    return 0;
}
