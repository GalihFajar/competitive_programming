#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

template <typename T> using v = vector<T>;
using ll = long long;
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

    vi pos(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pos[x] = i;
    }

    int l = pos[0], r = pos[0]; // 0 because all subrange must include 0
    ll res = 1;                 // case where the subrange is the whole array

    for (int mex = 1; mex < n; mex++) {
      int next_pos = pos[mex];

      if (l <= next_pos && next_pos <= r)
        continue;

      int diff_max = 2 * mex - 1; // max len allowed such that mex > med
				  // -1 is applied due to on the next logic, we're adding it, so we care about
				  // the difference (not the actual length)

      if (next_pos < l) {

        for (; l > next_pos; l--) {
          int r_max = min(l + diff_max, n - 1);

          res += max(r_max - r + 1, 0);
        }
      } else {
        for (; r < next_pos; r++) {
          int l_min = max(r - diff_max, 0);

          res += max(l - l_min + 1, 0);
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}

/*
 * Analysis:
 *
 * So the problem seems to do full search on each subsegment. 
 * But remember when some constraint is applied, perhaps we could "search" for other way to solve this.
 * Instead of checkinf every subsegment, calculating mex and med then compare, we could search all possibilities of mex instead.
 * So the mental model become like this: "If mex = x, what subsegment satisfies mex > med?"
 * This of course put the shift the focus into: "on what conditions the above statement satisfied?"
 * Here comes the hardest part of this problem, that is realizing on the observation:
     * To satisfy such conditions, the length of the subsegment is must be <= 2 * mex
     * The subsegment also must be in such a way that it's constructed of numbers {0, 1, ..., mex - 1}
     * To see why is this the case, you could immediately see that subsegment:
	 * {0, 1, 2, ...., mex - 1, ...} would have median > mex - 1 when the length is length than 2 * mex.
	 * Because, on length > 2 * mex, the median shifts to the right (past mex - 1) and make the median greater than mex
 * So with such observation, we could iterate through all the mex, and search the subsegments that satisfy the condition.
 * The construction here is also important:
     * We always start window from 0, since if we don't include 0, then the median will always be bigger (mex will always equals 0).
     * We always start mex from 1, because if mex = 0, all med will be greater than 0.
     * Then we iterate from the smallest mex, to the biggest mex.
     * In the process, we're spotting the next mex, whether it's on the left or right of the current window, then we expand the window accordingly.
     * For every expansion, there would be [l, r + 1]; [l, r + 2] ....; [l, r_max] new subsegments (vice versa on the opposite direction)
     * Then we summed up all this.
     * The res starts from 1 because when the subsegment = whole array, the value of mex = n + 1 (guaranteed bigger than median)
 */
