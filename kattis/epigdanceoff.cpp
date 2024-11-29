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

    int row, col; cin >> row >> col;
    vector<string> in;
    for (int i = 0; i < row; i++) {
        string t; cin >> t;
        in.push_back(t);
    }

    int total = 1;

    for (int i = 0; i < col; i++) {
        bool blank = true;
        for (int j = 0; j < row; j++) {
            if (in[j][i] != '_')
                blank = false;
        }

        if (blank) total++;
    }

    cout << total << '\n';

    return 0;
}
