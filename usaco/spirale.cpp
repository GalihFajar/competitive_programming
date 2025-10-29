#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = v<pii>;

#define all(x) begin(x), end(x)
#define fio(name)                                                              \
  freopen(name ".in", "r", stdin);                                             \
  freopen(name ".out", "w", stdout);
#define psp(x) cout << x << " ";
#define pnl(x) cout << x << "\n";

template <typename T> void print_v(vector<T> &v) {
  for (auto const &elem : v) {
    cout << elem << " ";
  }
  cout << endl;
}

template <typename K, typename T> void print_v(vector<pair<K, T>> &v) {
  for (auto const &elem : v) {
    cout << elem.first << " " << elem.second << " ";
  }
  cout << endl;
}

vpii cw_movt = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vpii ccw_movt = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")
  vvi field = vvi(100, vi(100, INT_MAX));
  int n, m, k;
  cin >> n >> m >> k;
  int row, col, z;

  for (int i = 0; i < k; i++) {
    cin >> row >> col >> z; // 0 cw, 1 ccw
    row--;
    col--;

    int steps_len = 1;
    int steps_left = 2;
    int direction_idx = 0;
    int current_visited = 0;
    int total_visited = n * m;
    int current_distance = 1;
    vpii &movt = z == 0 ? cw_movt : ccw_movt;

    auto update_dist = [&](int r, int c, int& cv, vvi& fld, int& cd) {
      if (r < 0 || c < 0 || r >= n || c >= m) {
        return;
      }

      cv++;
      fld[r][c] = min(fld[r][c], cd);
    };

    update_dist(row, col, current_visited, field, current_distance);
    while (current_visited < total_visited) {
      if (steps_left == 0) {
        steps_len++;
        steps_left = 2;
      }
      for (int _k = 0; _k < steps_len; _k++) {
        row += movt[direction_idx].first;
        col += movt[direction_idx].second;
        current_distance++;
        update_dist(row, col, current_visited, field, current_distance);
      }
      steps_left--;
      direction_idx = (direction_idx + 1) % 4;
    }
  }

  for (int i_ = 0; i_ < n; i_++) {
    for (int j_ = 0; j_ < m; j_++) {
      cout << field[i_][j_] << " ";
    }
    cout << "\n";
  }

  return 0;
}

/*
 *
 *
 */
