#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<string> vs;
typedef vector<vs> vvs;

unordered_map<char, vs> chr_br_map = {
    {'1', {"*.", "..", ".."}},
    {'2', {"*.", "*.", ".."}},
    {'3', {"**", "..", ".."}},
    {'4', {"**", ".*", ".."}},
    {'5', {"*.", ".*", ".."}},
    {'6', {"**", "*.", ".."}},
    {'7', {"**", "**", ".."}},
    {'8', {"*.", "**", ".."}},
    {'9', {".*", "*.", ".."}},
    {'0', {".*", "**", ".."}},
};

unordered_map<string, char> br_chr_map = {
    {"*.....", '1'},
    {"*.*...", '2'},
    {"**....", '3'},
    {"**.*..", '4'},
    {"*..*..", '5'},
    {"***...", '6'},
    {"****..", '7'},
    {"*.**..", '8'},
    {".**...", '9'},
    {".***..", '0'}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int n; cin >> n; if (n == 0) return 0;
        char c; cin >> c;

        if (c == 'S') {
            string in; cin >> in;
            vvs out;
            for (auto chr: in) {
                out.push_back(chr_br_map[chr]);
            }

            for (int k = 0; k < 3; k++)
                for (int i = 0; i < (int) out.size(); i++) {
                    if (i == (int) out.size() - 1)
                        cout << out[i][k] << '\n';
                    else
                        cout << out[i][k] << " ";
                }
        } else {
            vs temp(n, "");
            for (int k = 0; k < 3; k++) {
                for (int i = 0; i < n; i++) {
                    string s; cin >> s;
                    temp[i] += s;
                }
            }

            for (int i = 0; i < (int) temp.size(); i++) {
                if (i == (int) temp.size() - 1) {
                    cout << br_chr_map[temp[i]] << '\n';
                } else {
                    cout << br_chr_map[temp[i]] << "";
                }

            }
        }
    }

    return 0;
}
