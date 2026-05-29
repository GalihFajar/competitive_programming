#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
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

  fio("cowdance");

  int n, t_max;

  cin >> n >> t_max;
  vi a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans;

  ans = first_true(1, 1e6, [&](int k) {
    priority_queue<int> pq;
    int t = 0;
    int iter = 0;

    // init
    while (pq.size() < k && iter < n) {
      pq.push(-a[iter]);
      iter++;
    }

    while (!pq.empty()) {
      t += max(0, -pq.top() - t);
      pq.pop();

      if (iter < n) { // when something popped, then the time 
		      // for a[iter] is added by current time (t)
        pq.push(-(a[iter] + t));
        iter++;
      }
    }

    debug(k, t);

    return (t <= t_max);
  });

  cout << ans << endl;

  return 0;
}

/*
 *
 *
 */
