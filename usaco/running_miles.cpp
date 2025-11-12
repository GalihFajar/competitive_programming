#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

template <typename T> using v = vector<T>;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    //
    int tc; cin >> tc;
    while (tc--) {
	int n; cin >> n;
	vi b(n);


	for (int i = 0; i < n; i++) {
	    cin >> b[i];
	}

	vi pref_max(n), suff_max(n);

	for (int i = 0; i < n; i++) {
	    pref_max[i] = b[i] + i;
	    suff_max[i] = b[i] - i;
	}

	for (int i = 1; i < n; i++) {
	    pref_max[i] = max(pref_max[i], pref_max[i - 1]);
	}

	for (int i = n - 2; i >= 0; i--) {
	    suff_max[i] = max(suff_max[i], suff_max[i + 1]);
	}

	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
	    ans = max(ans, pref_max[i - 1] + b[i] + suff_max[i + 1]);
	}
	cout << ans << endl;
    }


    return 0;
}


/*
 * Seems like prefix sum work?
 * Ok we need to choose 3 from the entire range, so it wouldn't work as direct
 * Let's see hints...
 * Ok its another math-induced problems
 * So the logic is derived form the equation = b[i] + b[j] + b[k] - (r - l)
 * where we need to maximize the eq.
 * Now since we want to make the (r - l) the smallest possible, we could simplify,
 * eq = b[i] + b[j] + b[k] - (k - i) ==> eq = b[i] + i + b[j] + b[k] - k
 * Hence, we should maximize the point of mid (b[j]) then checking the max left of 
 * b[i] + i array and b[k] - k array. These are the prefix/suffix sums
 *
 *
*/
