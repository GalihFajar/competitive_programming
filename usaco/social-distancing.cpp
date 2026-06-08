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

using ll = long long;
using vpll = v<pair<ll, ll>>;

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

ll last_true(ll lo, ll hi, function<bool(ll)> f) {
  // if none of the values in the range work, return lo - 1
  lo--;
  while (lo < hi) {
    // find the middle of the current range (rounding up)
    ll mid = lo + (hi - lo + 1) / 2;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fio("socdist");
  int n, m;
  cin >> n >> m;
  vpll a;

  for (int i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }

  sort(all(a));

  ll ans;

  ans = last_true(1, 1e18, [&](ll d) {
    ll last_placed = a[0].first;
    int rem_cows = n - 1;
    ll next_possible;
    int iter = 0;
    // debug("init", last_placed);

    // debug(d);
    while (rem_cows && iter < m) {
      ll lb = a[iter].first, hb = a[iter].second;
      if (lb - last_placed >= d) {
        next_possible = lb;
      } else {
        next_possible = last_placed + d;
      }
      // debug(last_placed, next_possible);

      if (next_possible <= hb && next_possible >= lb) {
        rem_cows--;
        last_placed = next_possible;
      } else {
        iter++;
      }
    }

    return (rem_cows == 0);
  });

  cout << ans << endl;

  return 0;
}

/*
 *
 *
 */
