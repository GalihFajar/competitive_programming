#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> vvi;

void print_mat(vvi& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (j != mat[i].size() - 1) {
                cout << mat[i][j] << " ";
            } else {
                cout << mat[i][j] << "\n";
            }
        }
    }
}

int is_enemy(int x, int e, int n) {
    return (e == ((x + 1) % n)) || (e == x + 1);
}

vvi update(vvi& mat, int n) {
    vvi out = mat;

    auto is_out_of_bound = [&](int i, int j) {
        return i < 0 || j < 0 || i >= mat.size() || j >= mat[i].size();
    };

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (!is_out_of_bound(i + 1, j) && is_enemy(mat[i][j], mat[i + 1][j], n)) {
                out[i + 1][j] = mat[i][j];
            }

            if (!is_out_of_bound(i - 1, j) && is_enemy(mat[i][j], mat[i - 1][j], n)) {
                out[i - 1][j] = mat[i][j];
            }

            if (!is_out_of_bound(i, j + 1) && is_enemy(mat[i][j], mat[i][j + 1], n)) {
                out[i][j + 1] = mat[i][j];
            }

            if (!is_out_of_bound(i, j - 1) && is_enemy(mat[i][j], mat[i][j - 1], n)) {
                out[i][j - 1] = mat[i][j];
            }
        }
    }

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == 0 && b == 0 && c == 0 && d == 0) return 0;

        vvi b_map;
        for (int i = 0; i < b; i++) {
            vector<int> temp;
            for (int j = 0; j < c; j++) {
                int t; cin >> t;
                temp.push_back(t);
            }
            b_map.push_back(temp);
        }

        for (int i = 0; i < d; i++) {
            b_map = update(b_map, a);
        }

        print_mat(b_map);
    }

    return 0;
}
