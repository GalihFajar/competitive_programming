#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using ll = long long;
using vll = v<long long>;
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
    int tc; cin >> tc;
    while (tc--) {
	int n; cin >> n;
	vll v(n);
	ll total = 0;
	for (int i = 0; i < n; i++) {
	    cin >> v[i];
	}

	vll ans(n);
	total = (v[0] + v[n - 1]) / (n - 1);

	for (int i = 1; i < n - 1; i++) {
	    ans[i] = (v[i + 1] - v[i]) - (v[i] - v[i - 1]);
	    ans[i] /= 2;
	}
	ans[0] = (v[1] - v[0] + total) / 2;

	ll sum = 0;
	for (int i = 0; i < n - 1; i++) {
	    sum += ans[i];
	}
	ans[n - 1] = total - sum;

	print_v(ans);
    }

    // fio("<filename_prefix>")

    return 0;
}


/*
 *
 *
*/
