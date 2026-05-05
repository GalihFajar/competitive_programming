#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

template <typename T> using v = vector<T>;
using ll = long long;
using vll = v<ll>;
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

  // fio("<filename_prefix>")
  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;
    n *= 2;
    vi a(n);
    vi pos1(n, -1);
    vi pos2(n, -1);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
      if (pos1[x] == -1) {
        pos1[x] = i;
      } else {
        pos2[x] = i;
      }
    }

    int ans = 1;
    // case 1 -> 0 as center, check both
    auto case_1 = [&](int idx) -> int {
      int l = idx, r = idx;
      int N = a.size();
      if (l - 1 > 0 && a[l - 1] == 0) {
        l = l - 1;
      } else if (r + 1 < a.size() && a[r + 1] == 0) {
        r = r + 1;
      }

      unordered_set<int> include;

      while (l >= 0 && r < N) {
        if (a[l] == a[r]) {
          include.insert(a[l]);
        } else {
          break;
        }
        l--;
        r++;
      }

      int ans;
      for (int i = 0; i <= n; i++) {
        if (include.find(i) == include.end()) {
          return i;
        }

        ans = i;
      }

      return 1;
    };

    // case 2 -> 0 as part of palindrome, check the counterpart
    auto case_2 = [&]() -> int {
      int l = pos1[0], r = pos2[0];
      int N = a.size();
      unordered_set<int> include;

      // check if inner palindrome is valid
      while (l <= r) {
        debug("inner palindrome: ", l, r);
        if (a[l] != a[r]) {
          return 1; // inner palindrome not valid, return
        }

        include.insert(a[l]);
        l++;
        r--;
      }

      l = pos1[0], r = pos2[0];

      while (l >= 0 && r < N) {
        if (a[l] == a[r]) {
          include.insert(a[l]);
        } else {
          break;
        }

        l--;
        r++;
      }

      int ans;
      for (int i = 0; i <= n; i++) {
        if (include.find(i) == include.end()) {
          return i;
        }

        ans = i;
      }

      return 1;
    };

    ans = max(ans, case_1(pos1[0]));
    ans = max(ans, case_1(pos2[0]));
    ans = max(ans, case_2());

    cout << ans << endl;
  }

  return 0;
}

/*
 *
 *
 */
