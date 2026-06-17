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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    int n; cin >> n;
    v<pii> v(n);

    for (int i = 0; i < n; i++) {
	int a, b; cin >> a >> b;
	v[i] = {a, b};
    }

    sort(all(v));


    int ans = 0;
    int min_y = n + 1;
    for (int i = 0; i < n; i++) {
	int x, y;
	tie(x, y) = v[i];
	min_y = min(y, min_y);

	ans += (y == min_y);
    }

    cout << ans << endl;
    

    return 0;
}


/*
 *
 *
*/
