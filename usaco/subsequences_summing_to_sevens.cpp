
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
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

    fio("div7")
    int n; cin >> n;
    vi input;

    for (int _i = 0; _i < n; _i++) {
	int x; cin >> x;

	input.push_back(x);
    }

    vll pref_sum(n + 1);

    for (int i = 1; i < n + 1; i++) {
	pref_sum[i] = input[i - 1] + pref_sum[i - 1];
    }

    int current_max_len = -10;
    for (int i = 0; i < n + 1; i++) {
	for (int j = 0; j < i && i - j >= current_max_len; j++) {

	    if ((pref_sum[i] - pref_sum[j]) % 7 == 0) {
		current_max_len = max(current_max_len, i - j);
	    }
	}
    }

    cout << current_max_len << endl;

    return 0;
}


/*
 * should be simple prefix sum
 * lets implement
 * got WA and TLE, but I already know the problem: should return early + data type not long enough (should use long long)
 * AC
 *
 *
*/
