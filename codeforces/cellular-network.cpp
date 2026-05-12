#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define int long long

#ifdef LOCAL
#include "../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    for (int i = 0; i < n; i++) {
	cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
	cin >> b[i];
    } 

    int ans = -1;
    for (int i = 0; i < n; i++) {
	auto it = lower_bound(all(b), a[i]);
	int dist_at = LLONG_MAX;
	int dist_bef = LLONG_MAX;

	if (it != b.end()) {
	    dist_at = abs(a[i] - *it);
	}

	if (it != b.begin()) {
	    dist_bef = abs(a[i] - *prev(it));
	}
	int best = min(dist_bef, dist_at);

	ans = max(ans, best);
    }

    cout << ans << endl;

    return 0;
}


/*
 * 1 5 10 14 17
 * 4 11 15
 * 1 4 5 10 11 14 15 17
 *
 *
*/
