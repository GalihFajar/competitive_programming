#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

#ifdef LOCAL
#include "../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

#define int long long

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



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    int n;
    cin >> n;

    vi ls(n); 

    for (int i = 0; i < n; i++) {
	cin >> ls[i];
	ls[i] *= 2;
    }


    function <int(int, int, int)> rec = [&](int tot, int i, int cross_count) -> int{
	if (i >= n) {
	    return cross_count;
	}

	int with_neg = tot + -(ls[i]);
	int with_pos = tot + ls[i];
	int cross_count_neg = cross_count;
	int cross_count_pos = cross_count;

	if (tot > 0 && with_neg < 0) {
	    cross_count_neg++;
	} else if (tot < 0 && with_pos > 0){
	    cross_count_pos++;
	}

	return max(rec(with_neg, i + 1, cross_count_neg), rec(with_pos, i + 1, cross_count_pos));
    };

    cout << rec(1, 0, 0) << endl;

    return 0;
}


/*
 *
 *
*/
