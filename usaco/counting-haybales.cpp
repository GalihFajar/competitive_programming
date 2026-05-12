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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fio("haybales")

    int n, q;
    cin >> n >> q;

    vi v(n);

    for (int i = 0; i < n; i++) {
	cin >> v[i];
    }

    sort(all(v));

    while (q--) {
	int a, b; cin >> a >> b;
	cout << upper_bound(all(v), b) - lower_bound(all(v), a) << endl;
    }

    return 0;
}


/*
 *
 *
*/
