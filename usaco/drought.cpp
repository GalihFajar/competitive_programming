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

vi sums;
int calculate_p(vi &v, int i) {

  if (i > 0 && sums[i-1] != -1) {
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
    cin >> n;
    sums = vi(n + 10, -1);
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

    vector<ll>  p(n);
    p[0] = v[0];

    for (int i = 1; i < n; i++) {
      p[i] = v[i] - p[i - 1];
    }

    ll k = -1;

    if (n % 2 != 0) { // if odd
      k = p[n - 1];
    } else {
      ll temp = LLONG_MAX;
      for (int x = 0; x < n; x += 2) {
        temp = min(temp, p[x]);
      }
      k = temp;
    }

    if (k < 0) {
      cout << "-1\n";
      continue;
    }

    ll total = 0;

    if(([&]() -> int {
      for (int i = 0; i < n - 1; i++) {
        ll ki = p[i];
        if (i % 2 == 0) ki -= k;
        if (ki < 0) {
            cout << "-1\n"; return 1;
        }
        total += ki;
      }

      return 0;}())
    ){
      continue;
    };


    if (total < 0) {
	cout << "-1\n";
	continue;
    }

    cout << total*2 << endl;
  }

  return 0;
}

/*
 *
 *
 *
 */
