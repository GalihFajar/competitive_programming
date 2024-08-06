#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int a, b;
        unordered_set<int> alice, betty;
        int n_alice_can_choose = 0, n_betty_can_choose = 0;
        cin >> a >> b;

        if (a == 0 && b == 0) {
            return 0;
        }

        while (a--) {
            int in; cin >> in;
            alice.insert(in);
        }

        while (b--) {
            int in; cin >> in;
            betty.insert(in);
        }

        for (unordered_set<int>::iterator itr = alice.begin(); itr != alice.end(); itr++) {
            if (betty.find(*itr) == betty.end()) {
                n_betty_can_choose++;
            }
        }

        for (unordered_set<int>::iterator itr = betty.begin(); itr != betty.end(); itr++) {
            if (alice.find(*itr) == alice.end()) {
                n_alice_can_choose++;
            }
        }

        int out = n_betty_can_choose < n_alice_can_choose ? n_betty_can_choose : n_alice_can_choose;

        cout << out << '\n';
    }



    return 0;
}
