#include <iostream>
#include <vector>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vs = v<string>;
using vvs = v<vs>;

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

int is_out_of_bound(int i, int j, vs &v) {
  if (i < 0 || j < 0 || i >= v.size() || j >= v[i].size())
    return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")
  vs input;
  string x;
  while (cin >> x) {
    input.push_back(x);
  }

  v<pair<int, int>> movt = {{0, 1},  {1, 0},   {1, 1},  {0, -1},
                            {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}};

  int ans = 0;
  bool modified = false;
  do {
    modified = false;
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[i].size(); j++) {
        if (input[i][j] == '.')
          continue;
        int total = 0;
        for (pair<int, int> &x : movt) {
          int i_after = x.first + i;
          int j_after = x.second + j;

          if (is_out_of_bound(i_after, j_after, input))
            continue;
          if (input[i_after][j_after] == '@' || input[i_after][j_after] == '%')
            total++;
        }

        if (total < 4) {
          input[i][j] = '%';
          modified = true;
        }
      }
    }

    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input[i].size(); j++) {
        char &c = input[i][j];
        if (c == '%') {
          input[i][j] = '.';
          ans++;
        }
      }
    }
  } while (modified);

  cout << ans << endl;

  return 0;
}

/*
 *
 *
 */
