#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef vector<int> vi;

void merge(vi &arr, int p, int q, int r, long long &ops) {
  int nL = q - p + 1;
  int nR = r - q;
  vector<int> L, R;

  for (int i = p; i <= q; i++) {
    L.push_back(arr[i]);
  }

  for (int i = q + 1; i <= r; i++) {
    R.push_back(arr[i]);
  }

  int i = 0, j = 0, k = p;

  while (i < nL && j < nR) {
    if (L[i] < R[j]) {
      arr[k] = L[i++];
    } else {
      arr[k] = R[j++];
      ops += (L.size() - 1 - i) + 1;
    }
    k++;
  }

  while (i < nL) {
    arr[k++] = L[i++];
  }

  while (j < nR) {
    arr[k++] = R[j++];
  }
}

void merge_sort(vi &arr, int p, int r, long long &ops) {
  if (p >= r)
    return;
  int q = (p + r) / 2;

  merge_sort(arr, p, q, ops);
  merge_sort(arr, q + 1, r, ops);
  merge(arr, p, q, r, ops);
}

template <typename T> void print_vector(vector<T> &v) {
  for (auto elem : v) {
    cout << elem << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;

  while (1) {
    cin >> n;
    if (n == 0)
      return 0;
    vi input;
    long long ops = 0;
    while (n--) {
      int temp;
      cin >> temp;
      input.push_back(temp);
    }

    merge_sort(input, 0, input.size() - 1, ops);

    if (ops % 2 == 0) {
      cout << "Carlos\n";
    } else {
      cout << "Marcelo\n";
    }
  }

  return -1;
}
