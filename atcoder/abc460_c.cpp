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
using ll = long long;

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
    int n, m; cin >> n >> m;

    vi shari(n), neta(m);

    for (int i = 0; i < n; i++) {
	 cin >> shari[i];
    }

    for (int i = 0; i < m; i++) {
	cin >> neta[i];
    }


    sort(all(shari)); sort(all(neta));

    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
	debug(i, j);
	if (j < m && (ll) shari[i] * 2 >= (ll) neta[j]) {
	    j++;
	    ans++;
	}
    }

    cout << ans << endl;
    

    return 0;
}


/*
 *
 *
*/
