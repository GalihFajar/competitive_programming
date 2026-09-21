#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")

  string s, t;

  cin >> s >> t;

  string s_mod, t_mod;
  vi s_na_idx, t_na_idx;

  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (c != 'A') {
      s_mod += c;
      s_na_idx.push_back(i);
    }
  }

  for (int i = 0; i < t.size(); i++) {
    char c = t[i];
    if (c != 'A') {
      t_mod += c;
      t_na_idx.push_back(i);
    }
  }

  if (s_mod != t_mod) {
    cout << -1 << endl;
    return 0;
  }

  int m = s_na_idx.size();
  if (m == 0) {
      cout << abs((int) s.size() - (int) t.size()) << endl; 
      return 0;
  }

  int total = 0;
  for (int i = 0; i < m; i++) {
    if (i == 0) {
      debug(i, s_na_idx[i] - t_na_idx[i]);
      total += abs(s_na_idx[i] - t_na_idx[i]);
    } else {
      if (i - 1 >= 0) {
        debug(i, (s_na_idx[i] - s_na_idx[i - 1]) -
                     (t_na_idx[i] - t_na_idx[i - 1]));
        total += abs((s_na_idx[i] - s_na_idx[i - 1]) -
                     (t_na_idx[i] - t_na_idx[i - 1]));
      }
    }
  }

  if (m - 1 >= 0)
    total += abs(((int)s.size() - s_na_idx[m - 1]) -
                 ((int)t.size() - t_na_idx[m - 1]));
  cout << total << endl;

  // total += abs(s_na_idx[0] - t_na_idx[0]);
  // total += abs()

  return 0;
}

/*
 *
 *
 */
