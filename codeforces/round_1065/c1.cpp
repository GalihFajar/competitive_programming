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

pii count_one(vi& a, vi& b) {
    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < a.size(); i++) {
	if (a[i] == 1) cnt_a++;
	if (b[i] == 1) cnt_b++;
    }

    return {cnt_a, cnt_b};
}

bool is_odd(int x) {
    return x & 1;
}

void simulate(vi& a, vi& b) {
    pii cnt = count_one(a, b);
    int turn = 1;

    for (; turn <= a.size(); turn++)  {
	int idx = turn - 1;

	// ajisai play
	if (is_odd(turn)) {
	    if (is_odd(cnt.first)) {
		continue;
	    } else {
		if (a[idx] == b[idx]) continue;

		if (!is_odd(cnt.first) && a[idx] != b[idx]) {
		    if (b[idx] == 1) {
			cnt.first++; cnt.second--;
		    } else if (b[idx] == 0) {
			cnt.first--; cnt.second++;
		    }
		    swap(a[idx], b[idx]);
		    continue;
		}
	    }
	}

	// mai play
	if (!is_odd(turn)) {
	    if (is_odd(cnt.second)) {
		continue;
	    } else {
		if (a[idx] == b[idx]) continue;

		if (!is_odd(cnt.second) && a[idx] != b[idx]) {
		    if (a[idx] == 1) {
			cnt.second++; cnt.first--;
		    } else if (a[idx] == 0) {
			cnt.second--; cnt.first++;
		    }
		    swap(a[idx], b[idx]);
		    continue;
		}
	    }
	}
    }

    // cout << "======result======" << endl;
    // print_v(a); print_v(b);
    // cout << cnt.first << " " << cnt.second << endl;

    if ((is_odd(cnt.first) && is_odd(cnt.second)) || (!is_odd(cnt.first) && !is_odd(cnt.second))) {
	cout << "TIE" << endl;
    } else if (is_odd(cnt.first)) {
	cout << "AJISAI" << endl;
    } else {
	cout << "MAI" << endl;
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

	simulate(a, b);

    }

    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
