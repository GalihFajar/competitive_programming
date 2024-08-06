#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

char determine_p1_state(string& rps1, string& rps2) {
    string r = "rock";
    string p = "paper";
    string s = "scissors";

    if ((rps1 == r && rps2 == s) || (rps1 == p && rps2 == r) || (rps1 == s && rps2 == p))
        return 'w';
    else if (rps1 == rps2)
        return 'd';

    return 'l';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    bool first = true;

    while (1) {
        int n, k;
        cin >> n;
        if (n == 0)
            return 0;
        cin >> k;
        vector<pair<int, int>> players_states(n, {0, 0});

        if (!first) {
            cout << '\n';
        } else {
            first = false;
        }


        int total_games = k * (n * (n-1)) / 2;
        while (total_games--) {
            int p1, p2;
            string rps1, rps2;

            cin >> p1 >> rps1 >> p2 >> rps2;
            char p1_state = determine_p1_state(rps1, rps2);

            if (p1_state == 'w') {
                players_states[p1-1].first++;
                players_states[p2-1].second++;
            } else if (p1_state == 'l') {
                players_states[p2-1].first++;
                players_states[p1-1].second++;
            }
        }

        for (int i = 0; i < (int) players_states.size(); i++) {
            // printf("player %d, w: %d, l: %d\n", i + 1, players_states[i].first, players_states[i].second);
            int denom = players_states[i].first + players_states[i].second;

            if (denom == 0) {
                cout << "-" << '\n';
                continue;
            }

            float result = (float) (players_states[i].first) / denom;
            cout << setprecision(3) << fixed;
            cout << result << '\n';
        }
    }

    return 0;
}
