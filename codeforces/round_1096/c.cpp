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
    vi a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(all(a), [](int &el_1, int &el_2) -> bool {
      auto get_rank = [](int x) {
        if (x % 3 == 0 && x % 2 == 0)
          return 0; // Divisible by 3 (Highest Priority)
	if (x % 3 == 0)
	    return 1;
        if (x % 2 != 0 && x % 3 != 0)
          return 2; // Non-divisible by 2 or 3
        return 3;   // Divisible by 2 (Lowest Priority)
      };

      int rankA = get_rank(el_1);
      int rankB = get_rank(el_2);

      // 2. Compare by rank first
      if (rankA != rankB) {
        return rankA < rankB;
      }

      // 3. Optional: Tie-breaker (sort numerically within the same group)
      return el_1 < el_2;
    });
    print_v(a);
  }

  return 0;
}

/*
 *
 *
 */
