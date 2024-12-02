#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void print_mat(vvi& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++) {
            cout << mat[i][j];
        }
        cout << "\n";
    }
}

int mod_n(int a, int b) {
    return ((a % b) + b) % b;
}

void inc(vvi& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++) {
            mat[i][j] = (mat[i][j] + 1) % 10;
        }
    }
}

void dec(vvi& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++) {
            mat[i][j] =  mod_n((mat[i][j] - 1), 10);
        }
    }
}

void row_swap(vvi& mat, int a, int b) {
    for (int j = 0; j < mat.size(); j++) {
        swap(mat[a-1][j], mat[b-1][j]);
    }
}

void col_swap(vvi& mat, int a, int b) {
    for (int i = 0; i < mat.size(); i++) {
        swap(mat[i][a-1], mat[i][b-1]);
    }
}

void transpose(vvi& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = i; j < mat.size(); j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
}


vi parse_s(string& s) {
    vi out;

    for (int i = 0; i < s.size(); i++) {
        out.push_back(s[i] - '0');
    }

    return out;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int tc; cin >> tc;
  int x = 0;

  while (tc--) {
      int n; cin >> n;
      vvi mat;
      while (n--) {
          string temp; cin >> temp;
          mat.push_back(parse_s(temp));
      }

      cout << "Case #" << ++x << '\n';

      cin >> n;
      while (n--) {
          string op; cin >> op;
          if (op == "row") {
              int a, b; cin >> a >> b;
              row_swap(mat, a, b);
          } else if (op == "col") {
              int a, b; cin >> a >> b;
              col_swap(mat, a, b);
          } else if (op == "inc") {
              inc(mat);
          } else if (op == "transpose") {
              transpose(mat);
          } else if (op == "dec") {
              dec(mat);
          }
      }

      print_mat(mat);
      cout << '\n';
  }

  return 0;
}
