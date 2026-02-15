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

int root_val(int n) {
    while (n % 2 == 0) {
	n /= 2;
    }

    return n;
}

bool check(vi& v) {
    int n = v.size(); 

    for (int i = 1; i <= n; i++) {
	int val = v[i - 1];
	if (root_val(val) != root_val(i)) {
	    return false;
	}
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
	int n; cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) {
	    int x; cin >> x;
	    v[i] = x;
	}

	if (check(v)) {
	    cout << "YES\n";
	} else {
	    cout << "NO\n";
	}
    }

    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
