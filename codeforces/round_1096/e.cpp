#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../algo/misc/debug.h"
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

int main() {
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

	vi suff(n + 1, INT_MAX);
	vi change_at;
	

	for (int i = n - 1; i >= 0; i--) {
	    if (a[i] < suff[i + 1]) {
		change_at.push_back(i);
		suff[i] = a[i];
	    } else {
		suff[i] = suff[i + 1];
	    }
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
	    ans += (ll) a[i] - suff[i];
	}

	if (change_at.empty()) {
	    cout << ans << endl;
	    continue;
	}

	reverse(change_at.begin(), change_at.end());

	int chosen_pref_idx = 0;


	for (int i = 1; i < change_at.size(); i++) {
	    int prev_len = chosen_pref_idx == 0 ? change_at[chosen_pref_idx] : change_at[chosen_pref_idx] - change_at[chosen_pref_idx - 1];
	    // debug(prev_len);
	    // debug(change_at[i] - change_at[i - 1]);
	    if (change_at[i] - change_at[i - 1] > prev_len) {
		chosen_pref_idx = i;
	    }
	}

	debug(change_at);
	debug(suff);


	int beg = chosen_pref_idx == 0 ? -1 : change_at[chosen_pref_idx - 1];
	ans += change_at[chosen_pref_idx] - beg;

	cout << ans - 1 << endl;


    }

    return 0;
}


/*
 *
 *
*/
