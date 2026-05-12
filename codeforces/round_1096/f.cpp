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
	vi a(n + 1);
	vi cnt(n + 1);

	for (int i = 1; i <= n; i++) {
	    cin >> a[i];
	    cnt[a[i]]++;
	}

	vi have(n + 1);

	have[n] = cnt[n];

	for (int i = n - 1; i > 0; i--) {
	    have[i] = have[i + 1] + cnt[i];
	}
	debug(have);

	ll init = 0, after = 0;

	for (int i = 1; i <= n; i++) {
	    init += (ll) i * a[i];
	    after += (ll) have[i] * (2 * n - (ll) have[i] + 1) / 2;
	}

	ll cur = after - init, gain = -1;

	for (int i = 1; i <= n; i++) {
	    gain = max(gain, i - n + (ll) have[a[i]] - 1);
	}

	cout << cur + gain << endl;
    }

    return 0;
}


/*
 *
 *
*/
