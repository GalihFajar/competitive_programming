#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;
using vll = v<ll>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vc = v<char>;

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

void print_vs(vector<string> &v) {
  for (auto const &e : v) {
    cout << e << endl;
  }
}

template <typename T> void print_v_pair(vector<T> &v) {
  for (auto const &elem : v) {
    cout << '{' << elem.first << "," << elem.second << "} ";
  }
  cout << endl;
}

ll calc_area(pll a, pll b) {
  return (abs(a.first - b.first) + 1) * (abs(a.second - b.second) + 1);
}

bool is_valid(vs &field, pll a, pll b) {
  ll min_row, max_row, min_col, max_col;
  tie(min_row, min_col) = a;
  tie(max_row, max_col) = b;

  if (min_row > max_row)
    swap(min_row, max_row);
  if (min_col > max_col)
    swap(min_col, max_col);

  for (ll i = min_row; i <= max_row; i++) {
    if (field[i][min_col] == '.')
      return false;
  }
  for (ll i = min_row; i <= max_row; i++) {
    if (field[i][min_col] == '.')
      return false;
  }

  return true;
}

bool is_inside(double x, double y, v<pll> &points) {
  bool inside = false;

  int n = points.size();
  for (int i = 0, j = n - 1; i < n; j = i++) {
    if ((points[i].second > y) != (points[j].second > y) &&
        (x < (points[j].first - points[i].first) * (y - points[i].second) /
                     (double)(points[j].second - points[i].second) +
                 points[i].first)) {
      inside = !inside;
    }
  }

  return inside;
}

bool edges_intersect(ll min_x, ll max_x, ll min_y, ll max_y, v<pll> &points) {
  int n = points.size();
  for (int i = 0; i < n; i++) {
    pll p1 = points[i];
    pll p2 = points[(i + 1) % n];

    if (p1.first == p2.first) {
      ll x = p1.first; // x = p2.first also works
      ll y1 = min(p1.second, p2.second);
      ll y2 = max(p1.second, p2.second);

      if (x > min_x && x < max_x) {
        if (max(y1, min_y) < min(y2, max_y))
          return true;
      }
    } else {
      ll y = p1.second; // y = p2.second also works
      ll x1 = min(p1.first, p2.first);
      ll x2 = max(p1.first, p2.first);

      if (y > min_y && y < max_y) {
        if (max(x1, min_x) < min(x2, max_x))
          return true;
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")

  string s;
  v<pll> inputs;

  ll max_x = -1, max_y = -1;
  while (cin >> s) {
    stringstream ss(s);
    string t;
    vll p;
    while (getline(ss, t, ',')) {
      p.push_back(stoll(t));
    }

    inputs.push_back({p[0], p[1]}); // x, y
  }

  int n = inputs.size();

  ll ans = -1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll x1 = inputs[i].first;
      ll y1 = inputs[i].second;
      ll x2 = inputs[j].first;
      ll y2 = inputs[j].second;

      ll min_x = min(x1, x2);
      ll max_x = max(x1, x2);
      ll min_y = min(y1, y2);
      ll max_y = max(y1, y2);

      ll width = (max_x - min_x) + 1;
      ll height = (max_y - min_y) + 1;
      ll area = width * height;

      if (area <= ans)
        continue;

      double mid_x = (min_x + max_x) / 2.0;
      double mid_y = (min_y + max_y) / 2.0;

      if (!is_inside(mid_x, mid_y, inputs))
        continue;
      if (edges_intersect(min_x, max_x, min_y, max_y, inputs))
        continue;

      ans = area;
    }
  }

  cout << ans << endl;

  return 0;
}

/*
 *
 *
 */
