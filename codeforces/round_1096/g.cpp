#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

#define int long long

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

struct FenwickTree {
    int n;
    vector<int> bit;
    FenwickTree(int n) : n(n + 1), bit(n + 1) {}
    int query(int r) {
        int ret = 0;
        while(r > 0) {
            ret += bit[r];
            r -= (r & -r);    
        }

        return ret;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void update(int idx, int delta) {
        while(idx < n) {
            bit[idx] += delta;
            idx += (idx & -idx);
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    int tc; cin >> tc;

    while (tc--) {
	int n; cin >> n;
	vi a(n);

	for (int i = 0; i < n; i++) {
	    cin >> a[i];
	}

	vi pref(n + 1);

	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
	    if (i & 1) { // odd
		pref[i] = pref[i - 1] + a[i - 1];
	    } else {
		pref[i] = pref[i - 1] - a[i - 1];
	    }
	}

	// coord compression
	vi h = pref;
	sort(all(h));
	h.erase(unique(all(h)), h.end());
	auto get = [&](int x) {return lower_bound(h.begin(), h.end(), x) - h.begin() + 1;};

	FenwickTree fen_ev(h.size()), fen_od(h.size());
	int ans = 0;

	fen_ev.update(get(0), 1);

	for (int i = 1; i <= n; i++) {
	    int x = get(pref[i]);

	    if (i & 1) {
		ans += fen_ev.query(x - 1);
		fen_od.update(x, 1);
	    } else {
		ans += fen_od.query(x + 1, h.size());
		fen_ev.update(x, 1);
	    }
	}

	cout << ans << endl;
    }
    

    return 0;
}


/*
 *
 *
*/
