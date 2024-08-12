#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isLeap(int year) {
    if (year % 4 == 0) {
        if (year % 100 != 0)
            return true;
        else if (year % 400 == 0)
            return true;
    }

    return false;
}

bool isEndOfMonth(int d, int m, int y) {
    if (m == 2) {
        return (isLeap(y) && d == 29) || (!isLeap(y) && d == 28);
    }

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return d == 31;
    else
        return d == 30;
}

tuple<int, int, int> add(int d, int m, int y) {
    if (isEndOfMonth(d, m, y)) {
        if (d == 31 && m == 12)
            return {1, 1, y + 1};
        else
            return {1, m + 1, y};
    }

    return {d + 1, m, y};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (1) {
        int tc;
        bool isFirst = true;
        int cnt = 0;
        int total = 0;

        cin >> tc;
        if (tc == 0) return 0;

        tuple<int, int, int, int> prev;
        while (tc--) {
            int d, m, y, c;
            cin >> d >> m >> y >> c;

            if (isFirst) {
                isFirst = false;
            } else {
                int d_prev, m_prev, y_prev, c_prev;
                int d_next, m_next, y_next;

                tie(d_prev,m_prev,y_prev,c_prev) = prev;
                tuple<int, int, int> dmy_next = add(d_prev, m_prev, y_prev);
                tie(d_next, m_next, y_next) = dmy_next;

                if (d == d_next &&  m == m_next && y == y_next) {
                    cnt++;
                    total += abs(c - c_prev);
                }
            }

            prev = {d, m, y, c};
        }

        cout << cnt << " " << total << '\n';
    }

    return 0;
}
