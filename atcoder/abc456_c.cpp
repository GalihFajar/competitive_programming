#include <iostream>
#include <map>
#include <string>
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


#define int long long

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define fio(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout);
#define psp(x) cout << x << " ";
#define pnl(x) cout << x << "\n";

const int MOD = 998244353;

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    string s; cin >> s;
    int n; n = s.size();
    int r = 0;
    int l = 0;
    int sum = 0;
    while (l < n) {
	while (r + 1 < n && s[r] != s[r + 1]) {
	    r++;
	}
	int len = r - l + 1;
	debug(l, r, len);
	sum += (len * (len + 1) / 2) % MOD;
	r++;
	l = r;
    }

    cout << sum << endl;
    

    return 0;
}


/*
 *
 *
*/
