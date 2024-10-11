#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef unordered_map<string, char> usc;

usc map;

char translate(int c, int i) {
    if ((c / (int) pow(2, i)) % 2 == 0)
        return '/';
    return '\\';
}

void fill_map(usc& map) {
    for (int c = 0; c < 256; c++) {
        string s = "";
        for (int i = 0; i < 8; i++) {
            s += translate(c, i);
        }

        map[s] = (char) c;
        // cout << s << " " << (char) c << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill_map(map);

    // for (auto p: map) {
    //     cout << p.first << " " << (char) p.second << endl;
    // }

    string tc_;
    getline(cin, tc_);

    int tc = stoi(tc_);
    while (tc--) {
        vector<string> input;
        string s;
        int t = 11;
        while (t--) {
            getline(cin, s);
            if (s.empty()) break;
            input.push_back(s);
            // cout << input.back() << endl;
        }

        for (int j = 1; j < (int) input[0].size() - 1; j++) {
            string temp = "";
            for (int i = 1; i < 9; i++) {
                temp += input[i][j];
            }
            cout << (char) map[temp];
        }
        cout << endl;
    }

    return 0;
}
