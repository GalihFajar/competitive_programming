#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
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

int last_true(int lo, int hi, function<bool(int)> f) {
  // if none of the values in the range work, return lo - 1
  lo--;
  while (lo < hi) {
    // find the middle of the current range (rounding up)
    int mid = lo + (hi - lo + 1) / 2;
    if (f(mid)) {
      // if mid works, then all numbers smaller than mid also work
      lo = mid;
    } else {
      // if mid does not work, greater values would not work either
      hi = mid - 1;
    }
  }
  return lo;
}

int first_true(int lo, int hi, function<bool(int)> f) {
  hi++;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (f(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fio("convention");
  int n, m, c;
  cin >> n >> m >> c;
  vi a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(all(a));

  int ans;

  ans = first_true(0, 1e9, [&](int t) {
    int total_group = 1, current_capacity = 1, first = a[0];

    for (int i = 1; i < n; i++) {
      if (current_capacity + 1 > c) {
        total_group++;
        current_capacity = 1;
        first = a[i];
      } else {
        current_capacity++;
      }

      if (a[i] - first > t) {
        total_group++;
        current_capacity = 1;
        first = a[i];
      }
    }

    // debug(t, total_group, m);

    return total_group <= m;
  });

  cout << ans << endl;

  return 0;
}

/*
 *
 *
 */
