#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<pair<int, int>>  vpii;
typedef vector<vector<bool>> vvb;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vpii probs(26, {-1, -1});

    auto translate_idx = [](char c) -> int {
        return c - 'A';
    };
    

    int a, b, c;
    cin >> a >> b >> c;

    vvb is_solved_by_team(26, vector<bool>(b, false));
    char l_prob =  'A';
    while (c--) {
        int v, w; char x; string y;
        cin >> v >> w >> x >> y;
        l_prob = max(l_prob, x);

        if (y == "Yes" && !is_solved_by_team[translate_idx(x)][w]) {
            probs[translate_idx(x)] = {v, w};
            is_solved_by_team[translate_idx(x)][w] = true;
        }
    }

    for (char c = 'A'; c <= l_prob; c++) {
        pair<int, int> p_temp = probs[translate_idx(c)];
        if (p_temp.first != -1) {
            cout << c << " " << p_temp.first << " " << p_temp.second << '\n';
        } else {
            cout << c << " - -\n";
        }
    }

    return 0;
}
