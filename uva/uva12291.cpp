#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef vector<string> vs;

template <typename T> void print_vb(vector<vector<T>> &vb) {
  for (auto x : vb) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
}

bool check(vs &va, vs &vb) {
  int lim_a_row = va.size();
  int lim_a_col = va[0].size();

  vector<vector<bool>> check_vector(va.size(),
                                    vector<bool>(va[0].size(), false));

  int lim_b_row = vb.size();
  int lim_b_col = vb[0].size();

  int total_ast = [&]() -> int {
    int out = 0;
    for (auto s : vb) {
      for (auto c : s) {
        if (c == '*')
          out++;
      }
    }

    return out;
  }();

  for (int i = -10; i < lim_a_row + 10; i++) {
    for (int j = -10; j < lim_a_col + 10; j++) {
      vector<pair<int, int>> to_be_true;
      bool is_true = false;
      int check_total = 0;
      for (int k = 0; k < lim_b_row; k++) {
        for (int l = 0; l < lim_b_col; l++) {

          if (i + k < 0 || j + l < 0 || i + k >= va.size() ||
              j + l >= va[0].size()) {
            continue;
          }

          if ((vb[k][l] == '*' && va[i + k][j + l] == '*') && check_vector[i + k][j + l] != true) {
            check_total++;
            to_be_true.push_back({i + k, j + l});
          }
        }
      }

      is_true = check_total == total_ast;

      if (is_true) {
        for (auto p : to_be_true) {
          check_vector[p.first][p.second] = true;
        }
      }
    }
  }

  for (int i = 0; i < va.size(); i++) {
    for (int j = 0; j < va[i].size(); j++) {
      if (va[i][j] == '*' && check_vector[i][j] != true)
        return false;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  while (1) {
    cin >> a >> b;

    if (a == 0 && b == 0)
      return 0;

    vs va, vb;
    string temp;
    for (int i = 0; i < a; i++) {
      cin >> temp;
      va.push_back(temp);
    }

    for (int i = 0; i < b; i++) {
      cin >> temp;
      vb.push_back(temp);
    }

    cout << check(va, vb) << "\n";
  }

  return 0;
}
