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

unordered_map<int, int> dp;


int solve(int n, int k, int depth) {
    if (dp[n]) return INT_MAX;
    if (n == k) return depth;
    if (n == 1) return INT_MAX;
    int a, b;

    if (n % 2 == 0) {
	a = n / 2;
	b = a;
    } else {
	a = n/2;
	b = a + 1;
    }

    dp[n] = min(solve(a, k, depth + 1), solve(b, k, depth + 1));

    return dp[n];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;

    while (tc--) {
	dp.clear();
	int n, k;
	cin >> n >> k; 
	int ans = solve(n, k, 0);
	if (ans == INT_MAX) {
	    cout << -1 << endl;
	} else {
	    cout << ans << endl;
	}
    }

    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
