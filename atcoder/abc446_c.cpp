#include <bits/stdc++.h>
#include <queue>
using namespace std;

#ifdef LOCAL
#include "../algo/misc/debug.h"
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
    int n, d;
    cin >> n >> d;
    vi a(n);
    vi b(n);
    deque<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      q.push_back({a[i], i});
    }

    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    auto check = [&](int idx) -> bool {
      int egg, age;
      tie(egg, age) = q.front();

      if (age <= idx - d) {
        return true;
      }

      return false;
    };

    // eod
    for (int i = 0; i < n; i++) {
      // use the eggs
      int use = b[i];

      while (use && !q.empty()) {
        int egg, age;
        tie(egg, age) = q.front();

        q.pop_front();

        if (egg > use) {
          q.push_front({egg - use, age});
          use = 0;
        } else {
          use -= egg;
        }
      }

      while (!q.empty() && check(i)) {
        q.pop_front();
      }
    }

    int total = 0;
    while (!q.empty()) {
      total += q.front().first;
      q.pop_front();
    }

    cout << total << endl;
  }

  return 0;
}

/*
 *
 *
 */
