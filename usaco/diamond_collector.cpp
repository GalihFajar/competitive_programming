#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

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

  fio("diamond")
  int n, k;
  cin >> n >> k;

  vi d(n);

  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  sort(all(d));

  int l = 0, r = 0;
  int ans = 0;

  vi can_take_left(n, 0);
  for (; l < n; l++) {
      while (r < n && d[r] - d[l] <= k) {
	  r++;
      }
      can_take_left[l] = r - l;
  }

  vi max_after_i(n + 1, 0);

  for (int i = n - 1; i >= 0; i--) {
      max_after_i[i] = max(max_after_i[i+1], can_take_left[i]);
  }

  for (int l = 0; l < n; l++) {
      ans = max(ans, can_take_left[l] + max_after_i[l + can_take_left[l]]);
  }

  cout << ans << endl;

  return 0;
}

/*
 *
 *
 */
