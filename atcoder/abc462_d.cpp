#include <bits/stdc++.h>
using namespace std;

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

ll calculate(int x) {
    if (x <= 1) return 0;

    return (ll) x * (x - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    
    int n, d; cin >> n >> d;
    vi apps(1e6 + 5, 0);
    // debug(apps);
    for (int i = 0; i < n; i++) {
	int a, b; cin >> a >> b;
	b -= d;
	if (b < a) continue;
	apps[a]++;
	apps[b+1]--;
    }

    ll ans = 0;
    for (int i = 1; i < apps.size(); i++) {
	apps[i] += apps[i - 1];
	ans += (ll) calculate(apps[i]);
    }
    debug(apps);
    // debug(apps);

    cout << ans << endl;

    return 0;
}


/*
 *
 *
*/
