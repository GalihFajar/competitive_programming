#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
#define int long long

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

int cust_mod(int x, int y) {
  return x % y;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")

  int n, k;
  cin >> n >> k;

  vvi v;

  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    vi v_i;
    while (l--) {
      int x;
      cin >> x;
      v_i.push_back(x);
    }
    v.push_back(v_i);
  }

  int vec_idx = 0;
  int total_len = 0;
  int prev_len = 0;
  int prev_len_adjusted = 0;
  bool found = false;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    total_len += x * v[i].size();

    debug(k, total_len);
    if (!found && k <= total_len) {
      debug("mashook");
      vec_idx = i;
      prev_len_adjusted = prev_len;
      found = true;
    }

    prev_len = total_len;
  }

  debug(k, prev_len_adjusted);

  int idx_adjusted = k - prev_len_adjusted;
  debug("before", idx_adjusted);

  debug((int)v[vec_idx].size());
  debug((idx_adjusted % (int)v[vec_idx].size()));
  debug((idx_adjusted % (int)v[vec_idx].size()) - 1);
  idx_adjusted =
      max(0LL, (int)(cust_mod(idx_adjusted - 1, (int)v[vec_idx].size())));
  debug("after", idx_adjusted);

  cout << v[vec_idx][idx_adjusted] << endl;

  return 0;
}

/*
 *
 *
 */
