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

vvi const MOVE_LONG = {{2, 0}, {0, 2}};
vvi const MOVE_SHORT = {{1, 0}, {0, 1}};

bool reached(int x, int y, bool short_used, int const& target_x, int const& target_y) {

    if (x == target_x && y == target_y) {
	return true;
    }

    if (x > 10 || y > 10) {
	return false;
    }

    bool ans = false;

    for (auto const& p: MOVE_LONG) {
	// debug(x, y, target_x, target_y, p);
	ans = ans || reached(x + p[0], y + p[1], short_used, target_x, target_y);
    }

    if (!short_used) {
	for (auto const& p: MOVE_SHORT) {
	    ans = ans || reached(x + p[0], y + p[1], true, target_x, target_y);
	}
    }


    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    //
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
	int a, b; cin >> a >> b;
	if (reached(0, 0, false, a, b)) {
	    cout << "YES\n";
	} else {
	    cout << "NO\n";
	}
    }
    

    return 0;
}


/*
 *
 *
*/
