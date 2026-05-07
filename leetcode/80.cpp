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
    int removeDuplicates(vector<int>& nums) {
	
	int slow = 0, fast = 0;

	while (fast < nums.size()) {
	    if (slow - 2 >= 0 && nums[slow - 2] == nums[fast]) {
		fast++; continue;
	    }

	    nums[slow++] = nums[fast++];
	}

	return slow;
    }
};


/*
 *
 * [1, 1, 2, 2, 2, 3]
 *        l  r
 * [1, 1, 3, 2, 2, _]
 *
 * [1 1 2  1 1 1 1 2 2 3]
 *      l           r
*/
