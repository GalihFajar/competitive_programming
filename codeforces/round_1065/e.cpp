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

template <typename T> void print_v_cont(vector<T> &v) {
  for (auto const &elem : v) {
    cout << elem << " ";
  }
}

void process(int x) {
  vi evens, div_3, rest;

  for (int i = 1; i <= x; i++) {
    if (i % 2 == 0) {
      evens.push_back(i);
    } else if (i % 3 == 0) {
      div_3.push_back(i);
    } else {
      rest.push_back(i);
    }
  }

  vi buffer = evens;
  buffer.insert(buffer.end(), div_3.begin(), div_3.end());

  vi result;
  int buf_iter = 0;

  for (int x : rest) {
    if (x == 1) {
      result.push_back(x);
      continue;
    }

    if (buf_iter < buffer.size())
      result.push_back(buffer[buf_iter++]);
    if (buf_iter < buffer.size())
      result.push_back(buffer[buf_iter++]);
    result.push_back(x);
  }

  while (buf_iter < buffer.size()) {
    result.push_back(buffer[buf_iter++]);
  }

  print_v(result);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // fio("<filename_prefix>")

  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    process(x);
  }
  return 0;
}

/*
 *
 * Ok so my idea is that we can concatentate some array with, for example, multiple of them, and stitch them together
 * For example 1, 2, 4, 6 then later 3, 9, 15
 * Concatenate them together and we'll maybe have the answer
 * So it's wrong answer!
 * Lets ask LLM
 * So the idea is quite there! The solution supposed to hide the lonely numbers
 * These lonely numbers appear due to, say if the size of the next multiple is lower than the test case -> e.g. 7, 14 if x = 10 then 14 will never be there
 * We'll hide the lonely number by making it x,x,-,x,x,- the '-' denote the number we must hide
 * Now the best choice is of course even numbers. For example 2,4,6,8 -> we can hide 2,4,5,6,8,7.
 * The problem is that what if we ran out of even numbers? The next best is the multiple of 3 -> 3,9,15,21.
 * Why is multiple of three the next best? Why not 5 or 7? The answer is that the gap between them will get bigger. 
 * As we can see only with multiple of 3, the gap is too big already (6 diff).
 * So we greedily choose these two arrays of bests, then we hide the lonely primes.
 * AC
 *
 */
