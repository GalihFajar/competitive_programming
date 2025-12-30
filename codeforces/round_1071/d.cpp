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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; 

    int tc; cin >> tc;
    while (cin >> n) {
	int arr_size = pow(2, n);
	vi a(pow(2, n));
	v<bool> used = v<bool>(pow(2, n), false);
	int max_pop_count = -1;
	int mask;
	for (int i = 0; i <= pow(2, n) - 1; i++) {
	    int current_pop_count = __builtin_popcount(i);
	    if (max_pop_count < current_pop_count) {
		mask = i;
		max_pop_count = current_pop_count;
	    }
	    a[i] = i;
	}

	vi out;

	while (out.size() != a.size()) {
	    vi candidate;
	    for (int i = 0; i <= pow(2, n) - 1; i++) {
		if ((mask & i) == mask && !used[i]) {
		    used[i] = true;
		    candidate.push_back(i);
		}
	    }
	    sort(all(candidate));
	    out.insert(out.end(), candidate.begin(), candidate.end());
	    mask = mask >> 1;
	}
	print_v(out);
    }

    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
