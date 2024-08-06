#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string r1 = "`1234567890-=";
    string r2 = "QWERTYUIOP[]\\";
    string r3 = "ASDFGHJKL;'";
    string r4 = "ZXCVBNM,./";
    vector<string> rows{r1, r2, r3, r4};
    unordered_map<char, char> dict;

    for (string row: rows) {
        for (int i = 1; i < (int) row.size(); i++) {
            dict[row[i]] = row[i - 1];
        }
    }

    while (1) {
        string input;
        getline(cin, input);
        if (cin.eof()) break;

        string out = "";
        for (char c: input) {
            if (dict.count(c)) {
                out += dict[c];
            } else {
                out += c;
            }
        }

        cout << out << '\n';
    }

    return 0;
}
