#include <bits/stdc++.h>
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
using vll = v<ll>;

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

ll first_true(ll lo, ll hi, function<bool(ll)> f) {
  hi++;
  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;
    if (f(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

void blast(vll &a, v<bool> &blasted, int blast_idx, int rad, int &total) {
  rad--;
  if (rad < 0)
    return;

  if (blasted[blast_idx] || !total) {
    return;
  } else {
    blasted[blast_idx] = true;
    total--;
  }


  int left_idx = blast_idx - 1;
  while (left_idx >= 0 && a[blast_idx] - a[left_idx] <= rad) {
    blast(a, blasted, left_idx, rad - 1, total);
    left_idx--;
  }

  int right_idx = blast_idx + 1;
  while (right_idx < a.size() && a[right_idx] - a[blast_idx] <= rad) {
    blast(a, blasted, right_idx, rad - 1, total);
    right_idx++;
  }
}

// ll f(ll rad, vll &a) {
//
//   for (int i = 0; i < a.size(); i++) {
//     v<bool> blasted(a.size());
//     int total = a.size();
//     blast(a, blasted, i, rad, total);
//     if (total == 0) {
//       return true;
//     }
//   }
//
//   return false;
// }
//
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  fio("angry")
  int n;
  cin >> n;
  vll a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans;

  ans = first_true(1, 1000, [&](ll rad) {
    for (int i = 0; i < a.size(); i++) {
      v<bool> blasted(a.size());
      int total = a.size();
      blast(a, blasted, i, rad, total);
      if (total == 0) {
        debug(rad, blasted);
        return true;
      }
    }

    return false;
  });

  cout << ans << ".0" << endl;

  return 0;
}

/*
 *
 *
 */
