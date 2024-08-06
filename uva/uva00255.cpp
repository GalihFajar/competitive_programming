#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// bool isDiagonal(int& a, int& b) {
//     return (abs(a - b) % 9 == 0 && (a % )) || (abs(a - b) % 7 == 0 && (a % 8 != 0 || b % 8 != 0));
// }

unordered_set<int> search_q_legal_moves(int q) {
    int bound_left = 0, bound_right = 7, bound_up = q % 8, bound_down = bound_up + 56;
    unordered_set<int> q_legal_moves;

    while (bound_left + 8 <= q) {
        bound_left += 8;
    }

    bound_right = bound_left + 7;

    for (int i = bound_left; i <= bound_right; i++) {
        q_legal_moves.insert(i);
    }

    for (int i = bound_up; i <= bound_down; i += 8) {
        q_legal_moves.insert(i);
    }

    return q_legal_moves;
}

unordered_set<int> search_q_legal_moves(int q, int k) {
    int bound_left = 0, bound_right = 7, bound_up = q % 8, bound_down = bound_up + 56;
    unordered_set<int> q_legal_moves;

    while (bound_left + 8 <= q) {
        bound_left += 8;
    }

    bound_right = bound_left + 7;

    for (int i = q; i >= bound_left && i != k; i--) {
        q_legal_moves.insert(i);
    }

    for (int i = q; i <= bound_right && i != k; i++) {
        q_legal_moves.insert(i);
    }

    for (int i = q; i >= bound_up && i != k; i -= 8) {
        q_legal_moves.insert(i);
    }

    for (int i = q; i <= bound_down && i != k; i += 8) {
        q_legal_moves.insert(i);
    }

    return q_legal_moves;
}


void printUnordered(unordered_set<int>& set) {
    vector<int> v;
    for (auto i: set) {
        v.push_back(i);
    }

    sort(v.begin(), v.end());

    cout << "[ ";
    for (auto i: v) {
        cout << i << " ";
    }
    cout << "]\n";
}

bool isNeighbor(int &a , int& b) {
    int temp_right = a % 8 != 7 ? a + 1 : -1;
    int temp_left = a % 8 != 0 ? a - 1 : -1;
    vector<int> kings_moves{temp_right, temp_left, a + 8, a - 8};
    // printUnordered(new_legal_moves);
    // cout << "found: " << new_legal_moves.find(57) !=
    for (int km: kings_moves) {
        if (km < 0 || km > 63) continue;
        if (km == b)
            return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, q, m;

    while (cin >> k >> q >> m) {
        if (cin.eof()) break;
        unordered_set<int> q_legal_moves = search_q_legal_moves(q, k);
        // cout << "queen legal moves: ";
        // printUnordered(q_legal_moves);

        // illegal state
        if (k == q) {
            cout << "Illegal state\n";
        // illegal moves
        } else if (m == k || m == q || q_legal_moves.find(m) == q_legal_moves.end()) {
            cout << "Illegal move\n";
        }  // move not allowed
        else if (isNeighbor(k, m)) {
            cout << "Move not allowed\n";
        } else {
            int temp_right = k % 8 != 7 ? k + 1 : -1;
            int temp_left = k % 8 != 0 ? k - 1 : -1;
            vector<int> kings_moves{temp_right, temp_left, k + 8, k - 8};
            unordered_set<int> new_legal_moves = search_q_legal_moves(m);
            vector<int> possibly_allowed;

            for (int km: kings_moves) {
                if (km < 0 || km > 63) continue;
                if (new_legal_moves.find(km) == new_legal_moves.end()) {
                    possibly_allowed.push_back(km);
                }
            }

            bool allowed = !possibly_allowed.empty();

            if (allowed)
                cout << "Continue\n";
            else
                cout << "Stop\n";
        }
    }

    return 0;
}
