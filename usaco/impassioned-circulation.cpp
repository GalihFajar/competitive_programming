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

  // fio("<filename_prefix>")
  int n;
  cin >> n;
  string s;
  cin >> s;

  vvi appears(26);

  int max_ans;
  for (int i = 0; i < s.size(); i++) {
    appears[s[i] - 'a'].push_back(i);
  }

  int q;
  cin >> q;

  // int temp_max = max_ans;
  while (q--) {
    max_ans = 0;
    int m;
    string temp;
    char c;

    cin >> m >> temp;
    c = temp[0];

    int char_idx = c - 'a';

    vi app_c = appears[char_idx];
    int k = app_c.size();

    if (k == n) {
      max_ans = n;
    } else if (k > 1) {
      // cout << "case 1: ";
      int l = 0, r = 0;
      for (; l < k; l++) {
        while (r < k - 1 && app_c[r + 1] - app_c[l] - (r + 1) + l <= m) {
          r++;
        }

        int range = app_c[r] - app_c[l] + 1;
        int gaps = range - (r - l + 1);
        max_ans = max(min(n, range + (m - gaps)), max_ans);
      }
    } else if (k == 1) {
      max_ans = max(min(n, m + 1), max_ans);
    } else {
      max_ans = max(min(n, m), max_ans);
    }

    cout << max_ans << endl;
  }

  return 0;
}

/*
 * Observation: 
   * If there's a gap between our target/operation, we must fill it as much as possible
   * Like if operation is (2, a) to axxaxxxa, we must fill the gap of 2 instead of 3
   * But on the same case of axxaxxxa with operation (3, a) we'd fill the 3
   * Another case might be axxaxxxxxxxa with opeartion (3, a). 
     * In this case, we'd still fill the gap of 2 but we still have excess 1.
     * Hence, we'd fill use the excess as long as it doesn't overfill n
   * So the basic idea is:
     * Find valid gaps that is as close to the number of operation
   * Other cases:
     * if no gaps -> we could use all the operations, but not overfill n
     * if no occurence -> use all operations, but not overfill n
     * if n == k, k is total appearance of a character -> we could change all, so it's n
 * So the hard part of the solution is the implementation, which is to find the gaps to fill.
 * We could use sliding window for this, with the constraint of the basic idea
 *
 * 
 */
