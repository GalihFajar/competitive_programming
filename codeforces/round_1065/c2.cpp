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


bool is_odd(int x) {
    return x & 1;
}

int xor_all(vi& x) {
    int ans = x[0];
    for (int i = 1; i < x.size(); i++) {
	ans ^= x[i];
    }

    return ans;
}

int msb_at(int x) {
    for (int i = 30; i >= 0; i--) {
	if ((x >> i) & 1) {
	    return i;
	}
    }

    return 0;
}

// WARN: Unused
vi count_msbs(vi& vec) {
    vi msbs(32, 0);

    for (int i = 0; i < vec.size(); i++) {
	msbs[msb_at(vec[i])]++;
    }

    return msbs;
}

void solve(vi& a, vi& b) {
    int s = (xor_all(a) ^ (xor_all(b)));

    if (s == 0) {
	cout << "TIE\n";
	return;
    }

    int msb_pos = msb_at(s);
    int target_bit = 1 << msb_pos;


    for (int i = a.size() - 1; i >= 0; i--) {
	int bit_a = a[i] & target_bit;
	int bit_b = b[i] & target_bit;

	if (bit_a != bit_b) {
	    int turn = i + 1;

	    if (turn % 2 == 0) {
		cout << "MAI\n";
		return;
	    } else {
		cout << "AJISAI\n";
		return;
	    }
	}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;

    while (tc--) {
	int n; cin >> n;

	vi a(n), b(n);

	for (int i = 0; i < n; i++) {
	    cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
	    cin >> b[i];
	}

	solve(a, b);
    }

    return 0;
}


/*
 *
 *
*/
