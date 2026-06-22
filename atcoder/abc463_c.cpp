#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
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

  int n;
  cin >> n;
  v<pii> maxes(n);
  v<pii> takahashis(n);
  priority_queue<pii> pq;
  pii curr_max;

  for (int i = 0; i < n; i++) {
    int h, l;
    cin >> h >> l;
    takahashis[i] = make_pair(h, l);
  }

  sort(all(takahashis),
       [&](pii &p1, pii &p2) { return p1.second < p2.second; });

  for (int i = n - 1; i >= 0; i--) {
    int h = takahashis[i].first, l = takahashis[i].second;

    if (i == n - 1) {
      maxes[i] = {h, l};
    } else {
      maxes[i] = {max(h, maxes[i + 1].first), l};
    }
  }

  debug(maxes);

  unordered_map<int, int> answer;

  int q;
  cin >> q;
  vi queries(q);

  for (int i = 0; i < q; i++) {
    cin >> queries[i];
  }

  vi sorted_queries = queries;

  sort(all(sorted_queries));
  debug(sorted_queries);

  int iter = 0;
  for (auto const &query : sorted_queries) {
    while (maxes[iter].second <= query) {
      iter++;
    }
    answer[query] = maxes[iter].first;
  }

  for (auto const &query : queries) {
    cout << answer[query] << "\n";
  }

  return 0;
}

/*
 *
 *
 */
