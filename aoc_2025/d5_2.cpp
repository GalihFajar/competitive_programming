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
using vs = vector<string>;
using ll = long long;
using pll = pair<long, long>;
using ull = unsigned long long;

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

vs split(string &s, char delim) {
  vs out;
  stringstream ss(s);

  string t;
  while (getline(ss, t, delim))
    out.push_back(t);

  return out;
}

v<pll> get_valid_ranges(v<pll> &ranges) {
  sort(all(ranges), [](pll &a, pll &b) -> bool { return a.first < b.first; });
  v<pll> valid_ranges;
  v<bool> visited((int)ranges.size(), false);

  pll current_merged = ranges[0];

  for (int i = 1; i < ranges.size(); i++) {
      pll next_range = ranges[i];

      if (current_merged.second >= next_range.first) {
	  current_merged.second = max(current_merged.second, next_range.second);
      } else {
	  valid_ranges.push_back(current_merged);
	  current_merged = next_range;
      }
  }

  valid_ranges.push_back(current_merged);

  return valid_ranges;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string input;
  v<pll> ranges;

  int input_count = 0;
  ull ans = 0;
  while (true) {
    getline(cin, input);
    if (input.empty()) {
      break;
    }

    vs splitted = split(input, '-');
    ranges.push_back({stoll(splitted[0]), stoll(splitted[1])});
  }

  v<bool> destroyed(ranges.size(), false);
  sort(all(ranges), [](pll &a, pll &b) -> bool { return a.first < b.first; });
  v<pll> valid_ranges = get_valid_ranges(ranges);

  for (auto const &x : valid_ranges) {
    ans += (x.second - x.first) + 1;
  }

  cout << ans << endl;

  return 0;
}

/*

   a-b c-d
   a c b d -> a-d
   a c d b -> a-b



*/
