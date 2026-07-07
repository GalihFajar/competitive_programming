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

    // fio("<filename_prefix>")
    int n; cin >> n;

    vvi v;
    for (int i = 0; i < n; i++) {
	int m; cin >> m;
	vi vi;
	while(m--) {
	    int x; cin >> x;
	    vi.push_back(x);
	}
	v.push_back(vi);
    }

    int a, b;
    cin >> a >> b;
    cout << v[a-1][b-1] << endl;
    

    return 0;
}


/*
 *
 *
*/
