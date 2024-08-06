#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;


bool isOutOfBound(vector<vector<char>>& v, int row, int col) {
    int rowBound = (int) v.size() - 1;
    int colBound = (int) v[0].size() - 1;

    return row < 0 || row > rowBound || col < 0 || col > colBound;
}

void printVec(vector<vector<char>>& v) {
    for (int i = 0; i < (int) v.size(); i++) {
        for (int j = 0; j < (int) v[0].size(); j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n, count = 0;
    while (cin >> m >> n) {
        if (m == 0 || n == 0) return 0;
        vector<vector<char>> input;
        vector<vector<char>> out(m, vector<char>(n));
        if (count != 0) cout << '\n';
        cout << "Field #" << ++count << ":\n";


        while (m--) {
            string row;
            vector<char> in;

            cin >> row;

            for (int i = 0; i < (int) row.size(); i++) {
                in.push_back(row[i]);
            }

            input.push_back(in);
        }

        for (int row = 0; (int) row < input.size(); row++) {
            for (int col = 0; (int) col < input[0].size(); col++) {
                int count = 0;
                if (input[row][col] == '*') {
                    cout << '*';
                    continue;
                }


                if (!isOutOfBound(input, row, col - 1) && input[row][col - 1] == '*')
                    count++;
                if (!isOutOfBound(input, row, col + 1) && input[row][col + 1] == '*')
                    count++;
                if (!isOutOfBound(input, row - 1, col) && input[row - 1][col] == '*')
                    count++;
                if (!isOutOfBound(input, row + 1, col) && input[row + 1][col] == '*')
                    count++;
                if (!isOutOfBound(input, row - 1, col - 1) && input[row - 1][col - 1] == '*')
                    count++;
                if (!isOutOfBound(input, row + 1, col - 1) && input[row + 1][col - 1] == '*')
                    count++;
                if (!isOutOfBound(input, row - 1, col + 1) && input[row - 1][col + 1] == '*')
                    count++;
                if (!isOutOfBound(input, row + 1, col + 1) && input[row + 1][col + 1] == '*')
                    count++;


                // out[row][col] = count - '0';
                cout << count;
            }
            cout << '\n';
        }
    }

    return 0;
}


/*
00 01 02 03 04
10

*/
