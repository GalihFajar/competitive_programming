#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef vector<string> vs;

int bubble_count(string s) {
  bool swapped = true;
  int swap_count = 0;
  if (s.size() == 1) return 0;
  do {
    swapped = false;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] > s[i + 1]) {
        swap(s[i], s[i + 1]);
        swap_count++;
        swapped = true;
      }
    }
  } while (swapped);

  return swap_count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
        cout << '\n'; continue;
    }
    vs inputs;
    vector<pair<int, int>> idx_dict;

    while (b--) {
      string in;
      cin >> in;
      inputs.push_back(in);
    }

    for (int i = 0; i < inputs.size(); i++) {
      idx_dict.push_back({i, bubble_count(inputs[i])});
    }

    sort(idx_dict.begin(), idx_dict.end(),
         [](pair<int, int> &p1, pair<int, int> &p2) -> bool {
           if (p1.second != p2.second)
             return p1.second < p2.second;
           return p1.first < p2.first;
         });

    for (auto p : idx_dict) {
      /*cout << inputs[p.first] << " swap count: " << p.second << '\n';*/
      cout << inputs[p.first] << '\n';
    }
    if (tc != 0) cout << '\n';
  }

  return 0;
}
