#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, string> pss;
typedef vector<pss>  vpss;

template <typename T>
int solve_idx(int i, vector<T>& v) {
    return i % ((int) v.size());
}

void print_vec(vector<string>& v) {
    for (int i = 0; i < (int) v.size(); i++) {
        if (i == (int) v.size() - 1) {
            cout << v[i] << '\n';
        } else {
            cout << v[i] << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int tc; cin >> tc; if (cin.eof()) return 0;
        vs ans(tc, "");
        vpss in;

        while (tc--) {
            string a, b; cin >> a >> b;
            in.push_back({a, b});
        }

        int iter = 0;
        for (int i = 0; i < in.size(); i++) {
            string card = in[i].first;
            string w = in[i].second;

            int j = 0; 
            while (j < (int) w.size()) {
                int idx = solve_idx(iter, in);
                if (ans[idx].empty()) {
                    if (j == (int) w.size() - 1) {
                        ans[idx] = card;
                    }
                    j++;
                }
                iter++;
            }
        }

        print_vec(ans);
    }

    return 0;
}
