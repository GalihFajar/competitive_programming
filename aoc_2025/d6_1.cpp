#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vs = v<string>;
using vvs = v<vs>;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")
  //
  string s;
  vvs input;
  while (getline(cin, s)) {
    stringstream ss(s);
    string t;
    vs temp;

    while (ss >> t) {
      temp.push_back(t);
    }

    // print_v(temp);

    input.push_back(temp);
  }

  ll ans = 0;

  for (int col = 0; col < input[0].size(); col++) {
    char op = (char)input.back()[col][0];
    // cout << "arg: " << input[0][col] << endl;
    ll base = stoi(input[0][col]);
    // int base = 0;
    for (int row = 1; row < input.size() - 1; row++) {
      // cout << op << " " << input[row][col] << " ";

      switch (op) {
      case '*':
        base *= stoi(input[row][col]);
	break;
      case '+':
        base += stoi(input[row][col]);
	break;
      }
    }
    // cout << "\nresult: " << base << endl;

    ans += base;
  }
  cout << ans << endl;

  return 0;
}

/*
 *
 *
 */
