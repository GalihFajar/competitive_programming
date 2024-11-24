#include <iostream>
#include <climits>
#include <cmath>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto is_jolly = [](int n, unordered_map<int, bool>& um) -> bool {
        if (n == 1) return true;

        for (int i = 1; i < n; i++) {
            if (!um.count(i)) return false;
        }

        return true;
    };

    while (1) {
        int tc; cin >> tc; if (cin.eof()) return 0;
        unordered_map<int, bool> um;
        bool first = true;
        int last_elem;
        int in;
        int n = tc;
        while (tc--) {
            cin >> in;
            if (first) {
                first = false;
                last_elem = in;
                continue;
            }

            um[abs(last_elem - in)] = true;
            last_elem = in;
        }

        if (is_jolly(n, um)) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }

    return 0;
}
