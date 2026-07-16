#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define int long long

#ifdef LOCAL
#include "../algo/misc/debug.h"
#else
#define debug(...) 42
#endif


template <typename T> using v = vector<T>;
using ll = long long;
using vll = v<ll>;
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
    int n, k; 
    unordered_map<int, int> map; // <key, total>
    cin >> n >> k;
    vi a(n);
    int sum = 0;
    v<pair<int, int>> pair_vect; // <total, key>

    for (int i = 0; i < n; i++) {
	cin >> a[i];
	sum += a[i];

	if (map.count(a[i]))
	    map[a[i]] += a[i];
	else 
	    map[a[i]] = a[i];
    }

    for (auto const& [key, total]: map) {
	pair_vect.push_back({total, key});
    }

    sort(all(pair_vect), greater<pii>());
    debug(pair_vect);
    debug(sum);

    for (int i = 0; i < k && i < pair_vect.size(); i++) {
	sum -= pair_vect[i].first;
    }

    cout << sum << endl;

    

    return 0;
}


/*
 *
 *
*/
