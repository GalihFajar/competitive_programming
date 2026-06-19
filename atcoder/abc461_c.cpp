#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

  int n, k, m;
  ll ans = 0;
  cin >> n >> k >> m;
  v<pii> gems(n);
  v<int> picks(n);
  v<int> removables(n);
  v<int> missing_reps;
  unordered_set<int> seen_colors;

  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    gems[i] = {b, a};
  }

  sort(all(gems), [&](pii &p1, pii &p2) {
    return p1.first > p2.first;
  });
  debug(gems);

  for (int i = 0; i < k; i++) {
      ans += gems[i].first;
      if (seen_colors.count(gems[i].second)) {
	  removables.push_back(gems[i].first);
      } else {
	  seen_colors.insert(gems[i].second);
      }
  }
  debug(ans);

  int colors_left = m - seen_colors.size();

  for (int i = k; i < n; i++) {
      if (!seen_colors.count(gems[i].second)) {
	  missing_reps.push_back(gems[i].first);
	  seen_colors.insert(gems[i].second);
      }
  }

  int i = 0;
  while (colors_left > 0) {
      ans -= removables.back();
      removables.pop_back();
      ans += missing_reps[i];
      colors_left--;
      i++;
  }

  cout << ans << endl;

  return 0;
}

/*
 *
 *
 */
