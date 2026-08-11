#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

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
using pq_min = priority_queue<T, vector<T>, greater<T>>;

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

    pq_min<int> pq;

    int n; cin >> n;


    for (int i = 0; i < n; i++) {
	int q, h;
	cin >> q >> h;

	if (q == 1) {
	    pq.push(h);
	} else {
	    while (!pq.empty() && pq.top() <= h) {
		pq.pop();
	    }
	}

	cout << pq.size() << endl;
    }

    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
