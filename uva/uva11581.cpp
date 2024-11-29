#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> vvi;

void print_matrix(vvi& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }

        cout << '\n';
    }
    cout << '\n';
}

bool is_out_of_bound(int i, int j, vvi& in) {
    return i < 0 || i >= in.size() || j < 0 || j >= in[0].size();
}

bool is_same_mat(vvi& mat1, vvi& mat2) {
    if(mat1.size() != mat2.size()) return false;
    for (int i = 0; i < mat1.size(); i++) {
        for (int j = 0; j < mat1[0].size(); j++) {
            if (mat1[i][j] != mat2[i][j])
                return false;
        }
    }

    return true;
}

vvi transform(vvi in) {
    vvi out(in.size(), vector<int>(in[0].size(), 0));

    for (int i = 0; i < in.size(); i++) {
        for (int j = 0; j < in[0].size(); j++) {
            if (!is_out_of_bound(i + 1, j, out)) {
                out[i][j] += in[i+1][j];
            }

            if (!is_out_of_bound(i - 1, j, out)) {
                out[i][j] += in[i-1][j];
            }

            if (!is_out_of_bound(i, j + 1, out)) {
                out[i][j] += in[i][j+1];
            }

            if (!is_out_of_bound(i, j - 1, out)) {
                out[i][j] += in[i][j-1];
            }
            out[i][j] = out[i][j] % 2;
        }
    }

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;

    auto f = [](vvi& v) {
        int num_of_t = 0;
        while (1) {
            vvi vt = transform(v);
            if (is_same_mat(vt, v)) {
                cout << num_of_t - 1 << '\n';
                return 0;
            }
            v = vt;
            num_of_t++;
        }
    };


    while (tc--) {
        vvi v;
        string s;
        for (int i = 0; i < 3; i++) {
            cin >> s;
            vector<int> temp;
            for (int i = 0; i < s.size(); i++) {
                temp.push_back(s[i] - '0');
            }
            v.push_back(temp);
        }

        f(v);
    }

    return 0;
}
