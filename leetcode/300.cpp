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
    int lengthOfLIS(vi& nums) {
	return lengthOfLISOptimized(nums); // comment out for suboptimal solution
	int n = nums.size();
	vi dp(n, 1);

	dp[0] = 1;

	for (int i = 1; i < n; i++) {
	    for (int j = 0; j <= i; j++) {
		if (nums[j] < nums[i]) {
		    dp[i] = max(dp[i], dp[j] + 1);
		}
	    }
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
	    ans = max(ans, dp[i]);
	}

	return ans;
    }

    // optimal solution
    int lengthOfLISOptimized(vi& nums) {
	vi tails;

	for (int i = 0; i < nums.size(); i++) {
	    int x = nums[i];
	    auto it = lower_bound(all(tails), x);

	    if (it == tails.end()) {
		tails.push_back(x);
	    } else {
		*it = x;
	    }
	}

	return tails.size();
    }
};


/*
 *
 *
*/
