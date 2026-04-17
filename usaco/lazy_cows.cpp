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

template <typename T> void print_vv(v<v<T>> &vv) {
  for (auto &v : vv) {
    print_v(v);
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fio("lazy")

  int n, k;
  cin >> n >> k;

  vvi a(n + 1, vi(n + 1));

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      cin >> a[i][j];
    }
  }

  auto rotate_point = [&](int i, int j) -> pair<int, int> {
    return {i + j, i - j + n};
  };

  vvi rot_a(2 * (n + 1), vi(2 * (n + 1)));
  vvi pref = rot_a;

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n + 1; j++) {
      int i_new = i + j;
      int j_new = i - j + (n + 1);

      rot_a[i_new][j_new] = a[i][j];
    }
  }

  int n_rot = rot_a.size();
  for (int i = 0; i < n_rot; i++) {
    for (int j = 0; j < n_rot; j++) {
      if (i - 1 < 0 || j - 1 < 0)
        continue;
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + rot_a[i][j];
    }
  }

  auto query = [&](int a, int b, int A, int B) -> int {
    return pref[A][B] - pref[a - 1][B] - pref[A][b - 1] + pref[a - 1][b - 1];
  };

  int max_ans = -1;
  for (int i = 0; i < n_rot; i++) {
    for (int j = 0; j < n_rot; j++) {
      int a = max(1, i - k), 
          b = max(1, j - k), 
          A = min(n_rot - 1, i + k),
          B = min(n_rot - 1, j + k);
      if (a < 0 || b < 0 || A >= n_rot || B >= n_rot || !pref[i][j])
        continue;

      max_ans = max(max_ans, query(a, b, A, B));
    }
  }
  cout << max_ans << endl;


  return 0;
}

/*
* Do prefix sum of total grass
* k -> ranges in rectangle - 4 trinagles on the side
    * Need custom algo to subtract
* With k, iterate on all ranges

---- complexity -----
* Prefix sum: N * N
* Search: N * N (check all ranges)
*/
