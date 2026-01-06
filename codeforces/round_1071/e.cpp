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
using ll = long long;
using vll = v<ll>;

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

int is_monopoly(string& s) {
    int c = s[0];
    for (int i = 1; i < s.size(); i++) {
	if (s[i] != c) return -1;
    }

    return c - '0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    int tc; cin >> tc;

    while (tc--) {
	int n, x, y;
	cin >> n >> x >> y;
	string s; cin >> s;
	vi ps(n);
	int temp;
	ll total_p = 0;

	for (int i = 0; i < n; i++) {
	    cin >> temp;
	    ps[i] = temp;
	    total_p += temp;
	}


	if (total_p > (ll) x + y) {
	    cout << "NO\n"; continue;
	}

	ll min_a = 0, min_b = 0;
	for (int i = 0; i < s.size(); i++) {
	    char c = s[i];
	    ll majority = (ps[i] / 2) + 1;
	    if (c == '0') {
		min_a += majority;
	    } else {
		min_b += majority;
	    }
	}

	int monopoly = is_monopoly(s);

	if (monopoly == 0) {
	    if (x >= y + n && x >= min_a) {
		cout << "YES\n";
	    } else {
		cout << "NO\n";
	    }

	    continue;
	} else if (monopoly == 1){
	    if (y >= x + n && y >= min_b) {
		cout << "YES\n";
	    } else {
		cout << "NO\n";
	    }
	    continue;
	}

	if (min_a <= (ll) x && min_b <= (ll) y) {
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
