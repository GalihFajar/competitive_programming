#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

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
    int jump(vi& nums) {
	int n = nums.size();
	vi steps(n, INT_MAX);

	for (int i = 0; i < nums.size(); i++) {
	    for (int j = 1; j <= nums[i] && i + j < n; j++) {
		steps[i + j] = min(steps[i + j], steps[i] != INT_MAX ? steps[i] + 1: 1);
	    }
	}

	return steps[n - 1] == INT_MAX ? 0 : steps[n - 1];
    }
};


/*
 *
 * [2, 3, 1, 1, 4]
 * [1, 1, 1, 0, 0]
 * [1, 1, 1, 2, 2]
 *
*/
