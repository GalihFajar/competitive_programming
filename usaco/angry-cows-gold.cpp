#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iomanip>
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
    a[i] *= 2;
  }

  sort(all(a));

  ll ans;

  auto check_left = [&](int pos, int power) {
    int cur_pos = pos, cur_power = power;

    while (cur_pos - cur_power > a.front()) {
      auto it = lower_bound(all(a), cur_pos - cur_power);
      int next_pos = *it;

      if (next_pos >= cur_pos) {
        return false;
      }

      cur_pos = next_pos;
      cur_power -= 2;
    }

    return true;
  };

  auto check_right = [&](int pos, int power) {
    int cur_pos = pos, cur_power = power;

    while (cur_pos + cur_power < a.back()) {
      auto it = prev(upper_bound(all(a), cur_pos + cur_power));
      int next_pos = *it;

      if (next_pos <= cur_pos) {
        return false;
      }

      cur_pos = next_pos;
      cur_power -= 2;
    }

    return true;
  };

  int min_power = first_true(0, a.back() - a.front(), [&](int power) {
    int best_pos = last_true(a.front(), a.back(),
                             [&](int pos) { return check_left(pos, power); });

    if (best_pos < a.front())
      return false;

    return check_right(best_pos, power);
  });

  cout << fixed << setprecision(1) << min_power / 2.0 << endl;

  return 0;
}

/*
 *
 *
 */
