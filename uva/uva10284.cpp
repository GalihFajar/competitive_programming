#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;


bool isOutOfBound(int row, int col, vector<vector<char>>& board) {
    return row >= 8 || row < 0 || col >= 8 || col < 0 || board[row][col] != '*';
}

void checkPawnWhite(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& occupied) {
    int x1, y1, x2, y2;
    pair<int, int> diagLeft = {row - 1, col - 1};
    pair<int, int> diagRight = {row - 1, col + 1};
    tie(x1, y1) = diagLeft;
    tie(x2, y2) = diagRight;

    if (!isOutOfBound(x1, y1, board))
        occupied[x1][y1] = true;

    if (!isOutOfBound(x2, y2, board))
        occupied[x2][y2] = true;
}

void checkPawnBlack(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& occupied) {
    int x1, y1, x2, y2;
    pair<int, int> diagLeft = {row + 1, col - 1};
    pair<int, int> diagRight = {row + 1, col + 1};
    tie(x1, y1) = diagLeft;
    tie(x2, y2) = diagRight;

    if (!isOutOfBound(x1, y1, board))
        occupied[x1][y1] = true;

    if (!isOutOfBound(x2, y2, board))
        occupied[x2][y2] = true;
}

void checkKing(int row, int col, vvc& board, vvb& occupied) {
    int start_row = row - 1;
    int start_col = col - 1;

    for (int i = start_row; i < row + 2; i++) {
        for (int j = start_col; j < col + 2; j++) {
            if (i == row && j == col) continue;
            if (!isOutOfBound(i, j, board))
                occupied[i][j] = true;
        }
    }
}

void checkRook(int row, int col, vvc& board, vvb& occupied) {
    int start_row = row, start_col = col;

    // going up
    start_row--;
    while (!isOutOfBound(start_row, start_col, board)) {
        occupied[start_row][start_col] = true;
        start_row--;
    }
    start_row = row; start_col = col;

    //going down
    start_row++;
    while (!isOutOfBound(start_row, start_col, board)) {
        occupied[start_row][start_col] = true;
        start_row++;
    }
    start_row = row; start_col = col;

    //going left
    start_col--;
    while (!isOutOfBound(start_row, start_col, board)) {
        occupied[start_row][start_col] = true;
        start_col--;
    }
    start_row = row; start_col = col;

    //going right
    start_col++;
    while (!isOutOfBound(start_row, start_col, board)) {
        occupied[start_row][start_col] = true;
        start_col++;
    }
    start_row = row; start_col = col;
}

void checkBishop(int row, int col, vvc& board, vvb& occupied) {

    int start_row = row, start_col = col;

    // going left up diag
    start_row--; start_col--;
    while (!isOutOfBound(start_row, start_col, board)) {
        occupied[start_row][start_col] = true;
        start_row--; start_col--;
    }
    start_row = row; start_col = col;

    //going left down diag
    start_row++; start_col--;
    while (!isOutOfBound(start_row, start_col, board)) {
        occupied[start_row][start_col] = true;
        start_row++; start_col--;
    }
    start_row = row; start_col = col;

    //going right up diag
    start_row--; start_col++;
    while (!isOutOfBound(start_row, start_col, board)) {
        occupied[start_row][start_col] = true;
        start_row--; start_col++;
    }
    start_row = row; start_col = col;

    //going right down diag
    start_row++; start_col++;
    while (!isOutOfBound(start_row, start_col, board)) {
        occupied[start_row][start_col] = true;
        start_row++; start_col++;
    }
    start_row = row; start_col = col;
}

void checkQueen(int row, int col, vvc& board, vvb& occupied) {
    checkBishop(row, col, board, occupied);
    checkRook(row, col, board, occupied);
}

void checkKnight(int row, int col, vvc& board, vvb& occupied) {
    if(!isOutOfBound(row - 1, col - 2, board))
        occupied[row - 1][col - 2] = true;

    if(!isOutOfBound(row - 2, col - 1, board))
        occupied[row - 2][col - 1] = true;

    if(!isOutOfBound(row - 1, col + 2, board))
        occupied[row - 1][col + 2] = true;

    if(!isOutOfBound(row - 2, col + 1, board))
        occupied[row - 2][col + 1] = true;

    if(!isOutOfBound(row + 1, col - 2, board))
        occupied[row + 1][col - 2] = true;

    if(!isOutOfBound(row + 2, col - 1, board))
        occupied[row + 2][col - 1] = true;

    if(!isOutOfBound(row + 1, col + 2, board))
        occupied[row + 1][col + 2] = true;

    if(!isOutOfBound(row + 2, col + 1, board))
        occupied[row + 2][col + 1] = true;
}

bool isNumber(char c) {
    char i = c - '0';
    return i >= 0 && i <= 9;
}


template <typename T>
void printMatrix(vector<vector<T>> v) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (1) {
        string input;
        cin >> input;
        if(cin.eof()) return 0;

        vector<vector<char>> board(8, vector<char>(8, '*'));
        vector<vector<bool>> occupied(8, vector<bool>(8));

        int curr_row = 0;
        int curr_col = 0;
        // init state
        for (auto c: input) {
            if (isNumber(c)) {
                char num = c - '0';
                while(num--) {
                    curr_col++;
                }
            } else if (c == '/') {
                curr_row++;
                curr_col = 0;
            } else {
                board[curr_row][curr_col] = c;
                occupied[curr_row][curr_col] = true;
                curr_col++;
            }
        }


        // check all occupied
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'P')
                    checkPawnWhite(i, j, board, occupied);
                else if (board[i][j] == 'p')
                    checkPawnBlack(i, j, board, occupied);
                else if (board[i][j] == 'b' || board[i][j] == 'B')
                    checkBishop(i, j, board, occupied);
                else if (board[i][j] == 'n' || board[i][j] == 'N')
                    checkKnight(i, j, board, occupied);
                else if (board[i][j] == 'r' || board[i][j] == 'R')
                    checkRook(i, j, board, occupied);
                else if (board[i][j] == 'q' || board[i][j] == 'Q')
                    checkQueen(i, j, board, occupied);
                else if (board[i][j] == 'k' || board[i][j] == 'K')
                    checkKing(i, j, board, occupied);
            }
        }

        // printMatrix(board);
        // printMatrix(occupied);

        int total_unoccupied = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (!occupied[i][j])
                    total_unoccupied++;
            }
        }

        cout << total_unoccupied << '\n';
    }


    return 0;
}
