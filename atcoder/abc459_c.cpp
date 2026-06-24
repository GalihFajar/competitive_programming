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

    int n, q; cin >> n >> q;
    vi a(3e5 + 1, 0), b(3e5 + 1, 0);
    int k = 0;

    for (int i = 0; i < q; i++) {
	int x, y; cin >> x >> y;

	if (x == 1) {
	    a[y]++;
	    b[a[y]]++;

	    if (b[a[y]] == n) k = a[y];
	} else {
	    if (y + k > q) 
		cout << 0 << endl;
	    else
		cout << b[y + k] << endl;
	}
    }
    

    return 0;
}


/*
 *
 *
*/
