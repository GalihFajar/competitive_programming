#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

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

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; 
    
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    //
    int tc;
    cin >> tc;

    while (tc--) {
	int n, k; 
	cin >> n >> k;

	int d = __builtin_ctz(n);
	int ans = 0;
	if (d + 1 > k) {
	    ans++;
	}

	for (int i = 0; i < d; i++) {
	    int t = k - i;

	    for (int j = t; j <= i; j++) {
		ans += nCr(i, j);
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
