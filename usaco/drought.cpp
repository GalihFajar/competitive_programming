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

vi sums;
int calculate_p(vi &v, int i) {

  if (sums[i-1] != -1) {
      sums[i] = v[i] - sums[i - 1];
      return sums[i];
  }

  int sign = 1;
  int total = 0;
  for (int j = i; j >= 0; j--) {
    total += sign * v[j];
    sign *= -1;
  }
  sums[i] = total;

  return total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")
  int t;
  cin >> t;

  while (t--) {
    int n;
    sums = vi(n + 10, -1);
    cin >> n;
    vi v;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }

    if (n == 2) {
      if (v[0] == v[1]) {
        cout << 0 << endl;
        continue;
      } else {
        cout << -1 << endl;
        continue;
      }
    }

    int k = -1;

    if (n % 2 != 0) { // if odd
      k = calculate_p(v, n - 1);
    } else {
      int last = calculate_p(v, n - 1);
      if (last != 0) {
        k = -1;
      } else {
        int temp = INT_MAX;
        for (int x = 0; x < n; x += 2) {
          temp = min(temp, calculate_p(v, x));
        }
        k = temp;
      }
    }

    if (k < 0) {
      cout << "-1\n";
      continue;
    }

    cout << "k: " << k << endl;

    int total = 0;

    for (int i = 0; i < n - 1; i++) {
    
      int temp = calculate_p(v, i);
      if (i % 2 == 0) temp -= k;
      cout << temp << endl;
      if (i % 2 != 0 && temp < 0) {
	  cout << "-1\n"; continue;
      }
      total += temp;
    }

    total *= 2;

    if (total < 0) {
	cout << "-1\n";
	continue;
    }

    cout << total << endl;
  }

  return 0;
}

/*
 *
 *
 *
 */
