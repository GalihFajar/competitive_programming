#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

#ifdef LOCAL
#include "../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vs = v<string>;

#define all(x) begin(x), end(x)
#define fio(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout);
#define psp(x) cout << x << " ";
#define pnl(x) cout << x << "\n";

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

class Solution {
public:
    bool wordBreak(string s, v<string>& dict) {

	int n = s.size(); 
	v<bool> dp(n + 1);

	dp[0] = true;
	for (int i = 0; i <= n; i++) {
	    for (auto const& word: dict) {
		int len = word.size();

		if (i - len >= 0 && dp[i - len] && s.compare(i - len, len, word) == 0) {
		    dp[i] = true;
		    break;
		}
	    }
	}

	return dp[n];
    }
};


/*
 *
 *
*/
