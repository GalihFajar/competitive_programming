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

    int tc;
    cin >> tc;
    int cs = 1;

    while (tc--) {
        int interval, delay;
        int a, b, c, d;
        int bit_status;
        int intervals;
        int temp_interval;
        vector<bool> active(4, 0), high_low(4, 0);
        vector<pair<int, int>> time_temps;
        vector<int> reads_at;
        vector<int> count(4, 0);
        vector<int> thermo;

        cin >> interval >> delay;
        cin >> a >> b >> c >> d;
        cin >> bit_status;
        cin >> intervals;

        thermo = {a, b, c, d};

        while (intervals--) {
            int time, temp;
            cin >> time >> temp;
            time_temps.push_back({time, temp});
        }

        int t_max = [&]() -> int {
            int t = 0;
            for (auto p: time_temps) {
                t += p.first;
            }

            return t;
        }();

        for (int i = delay; i <= t_max; i+= interval) {
            reads_at.push_back(i);
        }


        for (int i = 0; i < 4; i++) {
            active[i] = ((bit_status >> i) & 1);
            high_low[i] = ((bit_status >> (i + 4)) & 1);
        }

        int start = 0;
        pair<int, int> start_end;
        bool first = true;
        for (int i = 0; i < (int) time_temps.size(); i++) {
            if (first) {
                start_end = {0, time_temps[i].first};
                first = false;
            } else {
                start_end = {start_end.second + 1, time_temps[i].first + start_end.second};
            }

            int temp = time_temps[i].second;
            int read = false;

            for (auto r: reads_at) {
                read |= (r >= start_end.first) && (r <= start_end.second);
            }

            if (!read) continue;

            for (int j = 0; j < 4; j++) {
                count[j] += active[j] && (
                    ((high_low[j] == 1) && (temp > thermo[j])) || ((high_low[j] == 0) && (temp < thermo[j]))
                );
            }
        }

        cout << "Case " << cs++ << ": ";

        for (int i = 0; i < (int) count.size(); i++) {
            if (count[i] > 0)
                cout << "yes";
            else
                cout << "no";

            if (i != (int) count.size() - 1)
                cout << " ";
            else
                cout << '\n';
        }
    }

    return 0;
}
