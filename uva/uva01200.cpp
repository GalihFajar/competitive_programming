#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool is_digit(char c) {
    return c <= '9' && c >= '0';
}

pair<string, string> parse_eq(string& s) {
    string left = "", right = "";

    int i = 0;
    while (s[i] != '=') {
        left += s[i++];
    }
    i++;

    while (i < (int) s.size()) {
        right += s[i++];
    }

    return {left, right};
}

int reduce_x(string& s) {

    string x_s = "";
    int x_value = 0;

    for (int i = 0; i < (int) s.size(); i++) {
        int temp = i;
        if (s[i] == 'x') {

            while (temp - 1 >= 0 && is_digit(s[temp - 1])) {
                x_s.insert(0, 1, s[temp - 1]);
                temp--;
            }

            if (temp - 1 >= 0 && (s[temp - 1] == '-' || s[temp - 1] == '+')) {
                x_s.insert(0, 1, s[temp - 1]);
            }

            if (x_s.empty()) x_s = "1";
            else if ((int) x_s.size() == 1 && x_s[0] == '-') x_s = "-1";
            else if ((int) x_s.size() == 1 && x_s[0] == '+') x_s = "1";

            x_value += stoi(x_s);
            x_s = "";
        }
    }

    return x_value;
}

int reduce_c(string& s) {
    string x_s = "";
    int x_value = 0;

    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == 'x') {
            x_s = "";
            continue;
        }

        if (s[i] == '-' || s[i] == '+') {
            if (!x_s.empty()) {
                x_value += stoi(x_s);
                x_s = "";
            }
        }
        x_s += s[i];
    }

    if (!x_s.empty()) {
        x_value += stoi(x_s);
        x_s = "";
    }

    return x_value;
}

template <typename T>
void print_pair(pair<T, T> p) {
    cout << "{x=" << p.first << ',' << "c=" << p.second << "}";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string temp; getline(cin, temp);
    int tc = stoi(temp);

    while (tc--) {
        string s; getline(cin, s);
        pair<string, string> left_right = parse_eq(s);
        pair<int, int> left_pair = {reduce_x(left_right.first), reduce_c(left_right.first)};
        pair<int, int> right_pair = {reduce_x(left_right.second), reduce_c(left_right.second)};

        if (left_pair.first == right_pair.first && left_pair.second == right_pair.second) {
            cout << "IDENTITY\n";
        } else if (left_pair.first == right_pair.first && left_pair.second != right_pair.second) {
            cout << "IMPOSSIBLE\n";
        } else {
            int lx, lc, rx, rc;
            tie(lx, lc) = left_pair;
            tie(rx, rc) = right_pair;
            cout << (int) floor((double) (rc - lc) / (lx - rx)) << "\n";
        }
    }

    return 0;
}
