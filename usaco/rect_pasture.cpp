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
using vp = v<pii>;
using vvp = vector<vector<pii>>;

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

    int n; cin >> n;

    vp a;

    for (int i = 0; i < n; i++) {
	int x, y; cin >> x >> y;
	a.push_back({x, y});
    }

    vvi pref(n+1, vi(n+1));
    sort(all(a), [](pii& p1, pii& p2) -> bool {
	return p1.first < p2.first;
    });

    for (int i = 0; i < n; i++) {a[i].first = i + 1;};
    sort(all(a), [](pii& p1, pii& p2) -> bool {
	return p1.second < p2.second;
    });
    for (int i = 0; i < n; i++) {a[i].second = i + 1;};


    for (auto& x: a) {
	pref[x.first][x.second] = 1;
    }

    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
	    pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + pref[i][j];
	}
    }

    // this queries with 0-index in mind.
    auto query = [&](int x1, int y1, int x2, int y2) -> int {
	return pref[x2+1][y2+1] - pref[x1][y2+1] - pref[x2+1][y1] + pref[x1][y1];
    };

    long long ans = 0;
    for (int i = 0; i < n; i++) {
	for (int j = i; j < n; j++) {
	    int x1 = min(a[i].first, a[j].first) - 1;
	    int x2 = max(a[i].first, a[j].first) - 1;

	    ans += query(0, i, x1, j) * query(x2, i, n - 1, j);
	}
    }

    cout << ans + 1 << endl;



    // fio("<filename_prefix>")

    return 0;
}


/*
 *
 *
*/
