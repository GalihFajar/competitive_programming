#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;


bool is_out_of_bound(int i, int j, vvc& robo_map) {

    if (i < 0 || i >= robo_map.size() || j < 0 || j >= robo_map[0].size())
        return true;

    return false;
}

pii select_next(pii& curr_loc, vvc& robo_map, vvb& visited) {
    int i = curr_loc.first, j = curr_loc.second;
    if (!is_out_of_bound(i-1, j, robo_map) && !visited[i-1][j] && robo_map[i-1][j] == '0')
        return {i-1, j};
    if (!is_out_of_bound(i, j+1, robo_map) && !visited[i][j+1] && robo_map[i][j+1] == '0')
        return {i, j+1};
    if (!is_out_of_bound(i+1, j, robo_map) && !visited[i+1][j] && robo_map[i+1][j] == '0')
        return {i+1, j};
    if (!is_out_of_bound(i, j-1, robo_map) && !visited[i][j-1] && robo_map[i][j-1] == '0')
        return {i, j-1};

    // stuck
    return {-1, -1};
}

void update_robo_map(pii& curr_loc, vvc& robo_map, vvc& field) {
    int i = curr_loc.first, j = curr_loc.second;

    if (!is_out_of_bound(i-1, j, robo_map)) {
        robo_map[i-1][j] = field[i-1][j];
    }
    if (!is_out_of_bound(i, j+1, robo_map)) {
        robo_map[i][j+1] = field[i][j+1];
    }
    if (!is_out_of_bound(i+1, j, robo_map)) {
        robo_map[i+1][j] = field[i+1][j];
    }
    if (!is_out_of_bound(i, j-1, robo_map)) {
        robo_map[i][j-1] = field[i][j-1];
    }
}

template <typename T>
void print_mat(vector<vector<T>> v) {
    if (v.empty()) {
        cout << "invalid!" << '\n';
        return;
    }

    for (int i = 0; i < (int) v.size(); i++) {
        for (int j = 0; j < (int) v[0].size(); j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}

template <typename T>
void print_mat_custom(vector<vector<T>> v) {
    int col_size = v[0].size();
    string bup_frag = "|---";
    string bup = "";
    for (int i = 0; i < col_size; i++) {
        bup += bup_frag;
    }

    bup += '|';

    cout << bup << '\n';
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << "| " << v[i][j] << " ";
        }
        cout << "|\n";
        cout << bup << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int row_max, col_max;
        cin >> row_max >> col_max; if (row_max == 0 && col_max == 0) return 0;
        int a, b; cin >> a >> b;

        vector<vector<char>> field(row_max, vector<char>(col_max, '?'));
        vector<vector<char>> robot_map(row_max, vector<char>(col_max, '?'));
        vector<vector<bool>> visited(row_max, vector<bool> (col_max, false));

        for (int i = 0 ; i < row_max; i++) {
            for (int j = 0; j < col_max; j++) {
                char temp;
                cin >> temp;
                field[i][j] = temp;
            }
        }

        robot_map[a-1][b-1] = '0';
        visited[a-1][b-1] = true;
        pii curr_loc = {a-1, b-1};
        int move = 0;

        while (1) {
            update_robo_map(curr_loc, robot_map, field);
            pii next = select_next(curr_loc, robot_map, visited);
            int next_i = next.first, next_j = next.second;
            if (next_i == next_j && next_i == -1)
                break;
            curr_loc = next;
            visited[next_i][next_j] = true;
            move++;
        }

        cout << '\n';
        print_mat_custom(robot_map); cout << endl;
        cout << "NUMBER OF MOVEMENTS: " << move << '\n';
    }

    return -1;
}
