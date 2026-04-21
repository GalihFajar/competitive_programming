#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using ll = long long;
using vll = v<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = v<pii>;

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

void print_set(unordered_set<int> &us) {
  for (auto &x : us) {
    cout << x << " ";
  }
  cout << endl;
}

int const MAX_LEN = 2e5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, q;
    cin >> n >> q;

    vi a(n + 1);

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    string x;
    cin >> x;
    string s = "#";
    s += x;
    s += "#";

    vll appears(n + 2);

    for (int i = 1; i <= n; i++) {
      int x = min(i, a[i]), y = max(i, a[i]);
      if (min(i, a[i]) != max(i, a[i])) {
        appears[x]++;
        appears[y]--;
      }
    }

    for (int i = 1; i < appears.size(); i++) {
      appears[i] += appears[i - 1];
    }

    unordered_set<int> bad_idxs;

    // check for bad index
    for (int i = 1; i < s.size() - 1; i++) {
      if (s[i] == 'L' && s[i + 1] == 'R' && appears[i]) {
        bad_idxs.insert(i);
      }
    }

    auto toggle = [&](int x) {
      if (s[x] == 'L') {
        s[x] = 'R';
        bad_idxs.erase(x);

        if (s[x - 1] == 'L' && appears[x - 1]) {
          bad_idxs.insert(x - 1);
        }
      } else {
        s[x] = 'L';
	bad_idxs.erase(x-1);

        if (s[x + 1] == 'R' && appears[x]) {
          bad_idxs.insert(x);
        }
      }
    };

    while (q--) {
      int qu;
      cin >> qu;
      toggle(qu);

      if (bad_idxs.empty()) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }

  // fio("<filename_prefix>")

  return 0;
}

/*
 *
 *
 */
