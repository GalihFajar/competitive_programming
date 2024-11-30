#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void print_mat(vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (j == v[i].size() - 1) {
                cout << v[i][j] << '\n';
            } else {
                cout << v[i][j] << " ";
            }
        }
    }
}

void go_down(vector<vector<int>>& mat) {
    for (int j = 0; j < mat[0].size(); j++) {
        for (int i = mat.size() - 1; i >= 0; i--) {
            int iter = i;
            while(iter < mat.size() - 1 && mat[iter+1][j] == 0) {
                mat[iter + 1][j] = mat[iter][j];
                mat[iter][j] = 0;
                iter++;
            }
        }
    }

    for (int j = 0; j < mat[0].size(); j++) {
        for (int i = mat.size() - 2; i >= 0; i--) {
            if (mat[i][j] == mat[i + 1][j]) {
                mat[i + 1][j] = mat[i][j] * 2;
                mat[i][j] = 0;
                i--;
            }
        }
    }


    for (int j = 0; j < mat[0].size(); j++) {
        for (int i = mat.size() - 1; i >= 0; i--) {
            int iter = i;
            while(iter < mat.size() - 1 && mat[iter+1][j] == 0) {
                mat[iter + 1][j] = mat[iter][j];
                mat[iter][j] = 0;
                iter++;
            }
        }
    }
}

void rot_90_cw(vvi& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = i; j < mat[i].size(); j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < mat.size(); i++) {
        int l = 0, r = mat[i].size() - 1;
        while (l < r) {
            swap(mat[i][l], mat[i][r]);
            l++; r--;
        }
    }
}

void rot_90_ccw(vvi& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = i; j < mat[i].size(); j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int j = 0; j < mat[0].size(); j++) {
        int l = 0, r = mat.size() - 1;
        while (l < r) {
            swap(mat[l][j], mat[r][j]);
            l++; r--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> board(4);
    for (int i = 0; i < 4; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        board[i] = {a, b, c, d};
    }

    int command; cin >> command;
    if (command == 0) {
        rot_90_ccw(board);
        go_down(board);
        rot_90_cw(board);
    } else if (command == 1) {
        rot_90_ccw(board);
        rot_90_ccw(board);
        go_down(board);
        rot_90_ccw(board);
        rot_90_ccw(board);
    } else if (command == 2) {
        rot_90_cw(board);
        go_down(board);
        rot_90_ccw(board);
    } else {
        go_down(board);
    }

    print_mat(board);

    return 0;
}
