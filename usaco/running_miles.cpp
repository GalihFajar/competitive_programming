#include <iostream>
#include <queue>
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

vi prefix_sum(vi& input) {
    vi pref(input.size(), 0);
    for (int i = 1; i < pref.size(); i++) {
	pref[i] = input[i] + pref[i - 1];
    }

    return pref;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    //
    int n; cin >> n;

    for (int i_ = 0; i_ < n; i_++) {
	int k; cin >> k;
	vi inp(k + 1);
	for (int i = 1; i < k + 1; i++) {
	    int x; cin >> x;
	    inp[i] = x;
	}

	vi pref = prefix_sum(inp);
	int ans = INT_MIN;
	for (int i = 1; i < inp.size(); i++) {
	    for (int j = 1; j < i; j++) {
		if (i - j + 1 < 3) break;
		priority_queue<int> pq;
		if (ans <= (pref[i] - pref[j])) {
		    for (int x = j; x <= i; x++) {
			pq.push(-inp[x]);

			if (pq.size() > 3) pq.pop();
		    }

		    int current = 0;
		    while(!pq.empty()) {
			current += -pq.top();
			pq.pop();
		    }
		    /*cout << "\tcurrent: " << current << endl;*/
		    /*cout << "\t\ti, j: " << i << ", " << j << endl;*/

		    ans = max(ans, current - (i - j));
		}
	    }
	}
	cout << ans << endl;
    }
    

    return 0;
}


/*
 *
 *
*/
