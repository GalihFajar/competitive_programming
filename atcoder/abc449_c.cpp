#include <bits/stdc++.h>
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
  int n, l, r;
  cin >> n >> l >> r;
  r++;
  string s;
  cin >> s;
  ll total = 0;

  vi cnt(26);

  for (int i = 0; i < s.size(); i++) {
    if (i - l >= 0)
      cnt[s[i - l] - 'a']++;
    if (i - r >= 0)
      cnt[s[i - r] - 'a']--;

    total += cnt[s[i] - 'a'];
  }
  cout << total << endl;

  return 0;
}

/*
 *
 *
 */
