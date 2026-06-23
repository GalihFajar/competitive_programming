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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")
  int n, k;
  cin >> n >> k;
  v<pii> cloths(n);
  vi pref(100);

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cloths[i] = {a, b};
  }

  sort(all(cloths), [](pii &p1, pii &p2) { return p1.second < p2.second; });

  int pot_chosen = 1;
  pii chosen = cloths[0];
  for (int i = 1; i < cloths.size(); i++) {
    if (chosen.second >= cloths[i].first)
      continue;
    chosen = cloths[i];
    pot_chosen++;
  }

  if (pot_chosen < k) {
  debug(pot_chosen);
    cout << -1 << endl;
    return 0;
  }

  int ans = last_true(0, 1e9, [&](int x) { 
      pii chosen = cloths[0];
      int pot_chosen = 1;
      for (int i = 1; i < n; i++) {
	if (chosen.second + x <= cloths[i].first) {
	  chosen = cloths[i];
	  pot_chosen++;
	}
      }


      return pot_chosen >= k; 
  });

  cout << ans << endl;

  return 0;
}

/*
 *
 *
 */
