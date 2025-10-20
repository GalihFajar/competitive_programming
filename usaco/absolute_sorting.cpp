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

int ceildiv(int a, int b) {
    return (a + (b - 1)) / b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    int tc; cin >> tc;
    while (tc--) {
	int n; cin >> n;
	vi arr;

	for (int i = 0; i < n; i++) {
	    int x; cin >> x;
	    arr.push_back(x);
	}

	int at_most = INT_MAX;
	int at_least = INT_MIN;
	for (int i = 0; i < n - 1; i++) {
	    if (arr[i] < arr[i + 1]) {
		at_most = min(at_most, (arr[i] + arr[i + 1])/2); // upper boundary of x
	    } else if (arr[i] > arr[i + 1]){
		at_least = max(at_least, ceildiv(arr[i] + arr[i + 1], 2)); // lower boundary of x
	    }
	}

	int use = max(at_least, 0);
	cout << (at_least <= at_most ? use : -1) << endl; // range of x is valid
    }
    

    return 0;
}


/*
 *
 * 100% involves math
 * Brute force approach would be to try every integer, which is stupidly time-consuming
 * Next is to involve mean, median, etc.
 * Lets try tiny test case: 10 5
 * Since the value is absolute, then we need to subtract the two with the biggest values possible
 * Deduction 1, if array is flipped, then we can choose highest numbers possible. 10 5 -> choose 100 -> 90 95
 * 5 4 3 2 1 -> choose 100 -> 95 96 97 98 99
 * is already sorted -> 0
 * the problem is kind of two formations: abc where; a <= b && b >= c (mountains) and b <= a && b <= c
 * see hints
 * so case by case (comparing pairs) should work
 * all that we need to do is to choose the x that is valid (in range)
 * and we need to create range such that it is valid, and naturally be the smallest as possible
 * that means the upper bound is minimum, and the lower bound is maximum (hence shorter x range)
 *
*/
