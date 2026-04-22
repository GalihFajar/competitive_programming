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

    int n, x; 
    cin >> n >> x;

    v<pii> a(n);

    for (int i = 0; i < n; i++) {
	int k; cin >> k;
	a[i] = {k, i};
    }

    sort(all(a), [](pii& p1, pii& p2) -> bool {return p1.first < p2.first;});

    for (int i = 0; i < n; i++) {
	pii p = a[i];
	int target = x - p.first;

	int l = 0, r = n - 1;

	while (l < r) {
	    int x = a[l].first;
	    int y = a[r].first;

	    if (l == i) {
		l++; continue;
	    } else if (r == i) {
		r--; continue;
	    }


	    int total = x + y;
	    if (target == (total)) {
		cout << p.second + 1 << " " << a[l].second + 1 << " " << a[r].second + 1 << endl;
		return 0;
	    } else if (total > target) {
		r--;
	    } else {
		l++;
	    }
	}
    }

    cout << "IMPOSSIBLE\n";

    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
