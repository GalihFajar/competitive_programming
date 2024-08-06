#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<vector<bool>> vvb;

template <typename T>
void printMatrix(vector<vector<T>> v) {
    for (int i = 0; i < (int) v.size(); i++) {
        for (int j = 0; j < (int) v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}


bool is_out_of_bound(int row, int col) {
    return row < 0 || row > 4 || col < 0 || col > 4;
}

bool check_col(int start_row, int start_col, vector<vector<bool>>& visited) {
    int iter_row = start_row;
    int count = visited[start_row][start_col];

    // check up
    while (--iter_row >= 0) {
        count += visited[iter_row][start_col];
    }

    // check down
    iter_row = start_row;
    while (++iter_row <= 4) {
        count += visited[iter_row][start_col];
    }

    return count >= 5;
}

bool check_row(int start_row, int start_col, vvb& visited) {
    int iter_col = start_col;
    int count = visited[start_row][start_col];

    // check left
    while (--iter_col >= 0) {
        count += visited[start_row][iter_col];
    }

    iter_col = start_col;
    // check right
    while (++iter_col <= 4) {
        count += visited[start_row][iter_col];
    }

    return count >= 5;
}

bool check_diag(int start_row, int start_col, vvb& visited) {
    int iter_row = start_row, iter_col = start_col;
    int count = visited[start_row][start_col];

    // check up-left diag
    while (!is_out_of_bound(--iter_row, --iter_col)) {
        count += visited[iter_row][iter_col];
    }
    iter_row = start_row; iter_col = start_col;

    // check right-down diag
    while (!is_out_of_bound(++iter_row, ++iter_col)) {
        count += visited[iter_row][iter_col];
    }
    iter_row = start_row; iter_col = start_col;

    if (count >= 5) {
        return true;
    }

    count = visited[start_row][start_col];

    // check down-left diag
    while (!is_out_of_bound(++iter_row, --iter_col)) {
        count += visited[iter_row][iter_col];
    }
    iter_row = start_row; iter_col = start_col;

    // check right-up diag
    while (!is_out_of_bound(--iter_row, ++iter_col)) {
        count += visited[iter_row][iter_col];
    }
    iter_row = start_row; iter_col = start_col;


    return count >= 5;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        unordered_map<int, pair<int, int>> number_coordinate;
        vector<vector<bool>> visited(5, vector<bool>(5));
        visited[2][2] = true;
        vector<int> number_calls;

        int row = 0, col = 0;
        int count = 25;
        while (count--) {
            if (row == 2 && col == 2) {
                col++;
                continue;
            }

            int input; cin >> input;


            number_coordinate[input] = {row, col++};

            if (col > 4) {
                row++; col = 0;
            }
        }

        count = 75;
        while (count--) {
            int input; cin >> input;
            number_calls.push_back(input);
        }

        for (int i = 0; i < (int) number_calls.size(); i++) {
            int call = number_calls[i];
            // cout << "i: " << i << " call: " << call << endl;
            // cout << "call: " << call << '\n';

            if (number_coordinate.count(call)) {
                int row, col;
                tie(row, col) = number_coordinate[call];

                visited[row][col] = true;
                // printMatrix(visited);
                // cout << "=====" << endl;
                if (check_row(row, col, visited) || check_col(row, col, visited) || check_diag(row, col, visited)) {
                    cout << "BINGO after " << i + 1 << " numbers announced" << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}
