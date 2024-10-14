#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;


void print_mat(vector<string>& mat) {
    for (auto s: mat)
        cout << s << '\n';
}

void transpose_mat(vector<string>& mat) {
    for (int i = 0; i < (int) mat.size(); i++) {
        for (int j = 0; j <= i; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

void rotate_90_mat(vector<string>& mat) {
    transpose_mat(mat);
    for (int j = 0; j < (int) mat[0].size()/2; j++)
        for (int i = 0; i < (int) mat.size(); i++) {
            swap(mat[i][j], mat[i][((int) mat.size() - 1 - j)]);
        }
}

void test() {
    vector<string> a = {
        "abcd",
        "efgh",
        "ijkl",
        "mnop"
    };

    vector<string> b = {
        "abc",
        "def",
        "ghi"
    };

    rotate_90_mat(a);
    print_mat(a);
    cout << endl;
    rotate_90_mat(b);
    print_mat(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--) {
        string s;
        cin >> s;
        int len = s.length();
        int M = 0;

        for (int i = 0; i <= 10000/2; i++) {
            if (i * i >= len) {
                M = i; break;
            }
        }

        vector<string> v(M, string(M, '*'));

        int ptr = 0;
        for (int i = 0; i < M && ptr < (int) s.size(); i++) {
            for (int j = 0; j < M && ptr < (int) s.size(); j++) {
                v[i][j] = s[ptr++];
            }
        }

        rotate_90_mat(v);

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i][j] != '*')
                    cout << v[i][j];
            }
        }

        cout << endl;
    }

    return 0;
}
