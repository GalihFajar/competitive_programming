#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
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

int last_true(int lo, int hi, function<bool(int)> f) {
  lo--;
  while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    if (f(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}

template <typename T> void print_v(vector<T> &v) {
  for (auto const &elem : v) {
    cout << elem << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")
  int n, k;
  cin >> n >> k;
  vi a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(all(a));

  cout << last_true(1, 2e9, [&](int x) -> bool {
    long long ops_needed = 0;

    for (int i = n / 2; i < n; i++) {
      ops_needed += max(0, x - a[i]);
    }

    return ops_needed <= k;
  });

  return 0;
}

/*
 *
 *
 */
