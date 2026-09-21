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
  int n, q;
  cin >> n >> q;
  vi input(n);
  v<pii> sorted(n); // {value, idx}

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    sorted[i] = {val, i};
  }

  sort(all(sorted));
  debug(sorted);

  for (int _i = 0; _i < q; _i++) {
    int r;
    cin >> r;
    vi queries(r);
    for (int i = 0; i < r; i++) {
      cin >> queries[i];
      queries[i]--;
    }

    int i_min = 0;
    pii current_min = sorted[i_min];
    bool check = true;

    while (check) {
	bool broken = false;
	for (int i = 0; i < r; i++) {
	    if (current_min.second == queries[i]) {
		// debug(current_min.second, queries[i]);
		current_min = sorted[++i_min];
		broken = true;
		break;
	    }
	}

	check = broken;
    }


    cout << current_min.first << endl;
  }

  return 0;
}

/*
 *
 *
 */
