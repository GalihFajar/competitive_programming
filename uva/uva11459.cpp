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

    while (tc--) {
        int a, b, c;
        cin >> a >> b >> c;
        unordered_map<int, int> ladder, snake, jump;
        vector<int> player_states(a, 1);

        while (b--) {
            int x, y;
            cin >> x >> y;

            jump[x] = y;

        }

        int cnt = 0;
        bool end = false;

        while (c--) {
            int input;
            cin >> input;
            if (!end) {
                cnt = cnt % a;

                // int pos = player_states[cnt] + input;
                int* pos = &player_states[cnt];
                *pos += input;
                if (jump.find(*pos) != jump.end())
                    *pos = jump[*pos];

                if (*pos >= 100) {
                    end = true;
                    *pos = 100;
                }
                cnt++;
            }
        }

        for (int i = 1; i <= a; i++) {
            cout << "Position of player " << i << " is " << player_states[i - 1] << ".\n";
        }
    }

    return 0;
}
