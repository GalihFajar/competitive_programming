#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

template <typename t> using v = vector<t>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;

#define all(x) begin(x), end(x)
#define fio(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout);
#define psp(x) cout << x << " ";
#define pnl(x) cout << x << "\n";

template <typename t>
void print_v(vector<t>& v) {
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
	ll a, b, c;
	cin >> a >> b >> c;

	if (a < b) {
	    ll x = c % b;
	    if (x >= a) {
		cout << 0 << endl;
	    } else {
		cout << a - x << endl;
	    }
	} else {
	    ll curr = c / b;
	    ll x = c % b;

	    if (curr % 2 == 0) {
		cout << a - x << endl;
	    } else {
		cout << b - x << endl;
	    }


	}

    }
    

    return 0;
}


/*
 *
 *
*/
