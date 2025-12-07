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
  vs input;
  while (getline(cin, s)) {
    input.push_back(s);
  }

  ll ans = 0;
  

  char op = ' ';
  vs numbers;
  for (int col = input[0].size() - 1; col >= 0; col--) {
    string number = "";
    for (int row = 0; row < input.size(); row++) {
      if (input[row][col] == ' ') continue;
      if (input[row][col] == '*' || input[row][col] == '+') {
        op = input[row][col];
        break;
      }

      number += input[row][col];
    }

    if (!number.empty())
      numbers.push_back(number);


    if (op != ' ') {
      ll base = stoi(numbers[0]);
      for (int i = 1; i < numbers.size(); i++) {
        if (op == '*') {
          base *= stoll(numbers[i]);
        } else {
          base += stoll(numbers[i]);
        }
      }
      ans += base;

      numbers.clear();
      op = ' ';
    }
  }
  cout << ans << endl;

  return 0;
}

/*
 *
 *
 */
