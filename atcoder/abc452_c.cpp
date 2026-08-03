#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

#define int long long

template <typename T> using v = vector<T>;
using ll = long long;
using vll = v<ll>;
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
    
    int n; cin >> n;
    v<pii> p;
    for (int i = 0; i < n; i++) {
	int x, y;
	cin >> x >> y;
	p.push_back({x, y});
    }

    int m; cin >> m;
    v<string> vs(m);

    for (int i = 0; i < m; i++) {
	cin >> vs[i];
    }

    v<vvi> counts(11, vvi((int)'z' + 1, vi(11, 0)));

    for (auto& s: vs) {
	int pos = 0;
	int len = s.size();
	debug(s);
	for (auto& c: s) {
	    counts[len][c][pos++]++;
	}
    }


    for (auto& s: vs) {
	// unordered_map<string, int> um;
	if (s.size() != n) {
	    cout << "No\n";
	    continue;
	}
	bool is_invalid = false;
	for (int i = 0; i < n; i++) {
	    int a, b;
	    tie(a, b) = p[i];
	    // string x = "";
	    // x += to_string(a);
	    // x += s[i];
	    // x += to_string(b - 1);
	    // um[x]++;

		//    if (um[x] > counts[a][s[i]][b - 1]) {
		// cout << "No\n";
		// is_invalid = true;
		// break;
		//    }
	    if (counts[a][s[i]][b-1] == 0) {
		cout << "No\n";
		is_invalid = true;
		break;
	    }
	}

	if (!is_invalid) {
	    cout << "Yes\n";
	}
    }
    

    return 0;
}


/*
 *
 *
*/
