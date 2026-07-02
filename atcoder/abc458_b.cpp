#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vvi v(h, vi(w, 4));

  if (w == 1 && h == 1) {
      cout << 0 << endl;
      return 0;
  }

  if (w == 1 || h == 1) {
    v = vvi(h, vi(w, 2));
    v[0][0] = 1;
    v[h - 1][w - 1] = 1;
  } else {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if ((i == 0 && j == 0) || (i == (h - 1) && j == 0) ||
            (i == 0 && j == (w - 1)) || (i == (h - 1) && j == (w - 1))) {
          v[i][j] = 2;
        } else if (i == 0 || i == (h - 1) || j == 0 || j == (w - 1)) {
          v[i][j] = 3;
        }
      }
    }
  }

  for (vi &x : v) {
    print_v(x);
  }

  // fio("<filename_prefix>")

  return 0;
}

/*
 *
 *
 */
