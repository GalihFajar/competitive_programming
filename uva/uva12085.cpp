#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

void solve_seq(string& begin, string& end) {
    int i = 0;
    cout << begin;
    while (begin[i] == end[i]) {
        i++;
    }

    cout << '-';

    while (i < (int) begin.size()) {
        cout << end[i++];
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 1;
    bool very_first = true;

    while (1) {
        int tc; cin >> tc; if (tc == 0) return 0;
        int output_lines = 0;

        int start;
        int last;
        string start_str, last_str;
        bool first = true;
        string in_str;
        int in;
        while (tc--) {
            cin >> in_str;
            in = stoi(in_str);


            if (first) {
                start = in;
                last = in;
                start_str = in_str;
                last_str = in_str;
                first = false;

                cout << "Case " << cnt++ << ":\n";

                continue;
            }

            if (in - last != 1) {
                if (start == last) {
                    cout << start_str << "\n";
                } else {
                    solve_seq(start_str, last_str);
                }

                start = in;
                last = in;
                start_str = in_str;
                last_str = in_str;
            } else {
                last = in;
                last_str = in_str;
            }

        }


        if (in - last != 1) {
            if (start == last) {
                cout << start_str << "\n";
            } else {
                solve_seq(start_str, last_str);
            }

            start = in;
            last = in;

            start_str = in_str;
            last_str = in_str;
        } else {
            last = in;
            last_str = in_str;
        }
        cout << '\n';
    }

    return 0;
}
