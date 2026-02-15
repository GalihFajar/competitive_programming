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

bool is_adj(int a, int b) {
    if (a == 0) return true;
    return a + b != 7 && a != b;
}


int N;
vvi memo = vvi(300007, vi(7, -1));
vi input = vi(300007, 0);


int dp(int idx, int prev) {
    if (idx == N) return 0;

    if (memo[idx][prev] != -1) return memo[idx][prev];

    int best = INT_MAX;

    for (int x = 1; x <= 6; x++) {
	if (is_adj(prev, x)) {
	    int cost;
	    if (input[idx] == x) {
		cost = 0;
	    } else {
		cost = 1;
	    }

	    best = min(best, cost + dp(idx + 1, x));
	}
    }

    return memo[idx][prev] = best;
}

void solve() {
    int tc; cin >> tc; 
    while (tc--) {
	cin >> N;
	for (int i = 0; i < N; i++) {
	    cin >> input[i];
	    for (int j = 0; j < 7; j++) {
		memo[i][j] = -1;
	    }
	}

	cout << dp(0, 0) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    solve();

    // fio("<filename_prefix>")
    return 0;
}


/*
 *
 *
*/
