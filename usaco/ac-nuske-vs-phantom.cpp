#include <algorithm>
#include <bitset>
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

const int MAX_SIZE = 2e3;

template <typename T> void print_v(vector<T> &v) {
  for (auto const &elem : v) {
    cout << elem << " ";
  }
  cout << endl;
}

template <typename T> void print_v_bitset(vector<T> &v) {
  for (auto const &elem : v) {
    cout << elem << "\n";
  }
  cout << endl;
}

template <typename T> void print_vv(v<v<T>> &vv) {
  for (auto &elem : vv) {
    print_v(elem);
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")
  int n, m, q;
  cin >> n >> m >> q;

  /*
   * The next 4 loops can be combined one for-loop, but for ease of
   * understanding we have divided it.
   * Reading the grid:
   */
  vector<bitset<MAX_SIZE + 1>> grid(MAX_SIZE + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char a;
      cin >> a;
      grid[i][j] = (a == '1');
    }
  }

  vvi pref(MAX_SIZE + 1, vi(MAX_SIZE + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];

      if (grid[i][j]) {
        if (grid[i][j - 1] && grid[i - 1][j]) {
          pref[i][j]--;
        }

        if (!grid[i - 1][j] && !grid[i][j - 1]) {
          pref[i][j]++;
        }
      }
    }
  }

  vvi horpref(MAX_SIZE+1, vi(MAX_SIZE + 1));
  vvi verpref(MAX_SIZE+1, vi(MAX_SIZE + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      horpref[i][j] = horpref[i][j - 1];
      verpref[i][j] = verpref[i - 1][j];

      if (grid[i][j]) {
        horpref[i][j] += !grid[i][j - 1];
        verpref[i][j] += !grid[i - 1][j];
      }
    }
  }

  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = grid[a][b];

    ans += horpref[a][d] - horpref[a][b];
    ans += verpref[c][b] - verpref[a][b];

    ans += pref[c][d] - pref[a][d] - pref[c][b] + pref[a][b];

    cout << ans << endl;
  }

  return 0;
}

/*
 *
 *
 */
