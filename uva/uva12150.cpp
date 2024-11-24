
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;

void print_vec(vi& v) {
    for (int i = 0; i < v.size(); i++) {
        if (i != v.size() - 1) cout << v[i] << " ";
        else cout << v[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int tc; cin >> tc;
        if (tc == 0) return 0;

        vpii pole;
        while (tc--) {
            int a, b; cin >> a >> b;
            pole.push_back({a, b});
        }

        vector<int> start_pos(pole.size(), -1);

        auto solve_pos = [&]() -> int {
            for (int i = 0; i < (int) pole.size(); i++) {
                int new_idx = i + (pole[i].second);
                if (new_idx < 0 || new_idx >= pole.size()) {
                    return -1;
                }

                if (start_pos[new_idx] != -1) {
                    return -1;
                }

                start_pos[new_idx] = pole[i].first;
            }

            return 0;
        };

        if (solve_pos() == 0) {
            print_vec(start_pos);
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
