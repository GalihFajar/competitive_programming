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

    int tc; cin >> tc;
    int cnt = 1;

    while (tc--) {
        int n, i, k; cin >> n >> i >> k;
        int times_inactive = 0, instructions_ignored = 0;
        int active_time = 0;

        while (n--) {
            int t; cin >> t;

            if (active_time + i <= t) {
                times_inactive++;
                active_time = t + k;
            } else if (t < active_time) {
                instructions_ignored++;
            } else {
                active_time = t;
            }
        }

        cout << "Case " << cnt++ << ": " << times_inactive << " " << instructions_ignored << '\n';
    }

    return 0;
}
