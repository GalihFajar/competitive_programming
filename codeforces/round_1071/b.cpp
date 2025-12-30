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

int calculate(vi& in) {
    int ans = 0;
    for (int i = 1; i < in.size(); i++) {
	ans += abs(in[i] - in[i-1]);
    }

    return ans;
}

void solve(vi& in) {
    int total = calculate(in);
    int reduction = abs(in[1] - in[0]);

    for (int i = 1; i < in.size() - 1; i++) {
	int current = abs(in[i] - in[i - 1]) + abs(in[i] - in[i + 1]);
	int rem_dist = abs(in[i + 1] - in[i - 1]);
	int curr_reduct = current - rem_dist;
	reduction = max(reduction, curr_reduct);
    }

    reduction = max(reduction, abs(in[in.size() - 1] - in[in.size() - 2]));

    cout << total - reduction << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    while (n--) {
	int tc; cin >> tc;
	vi input;
	while (tc--) {
	    int x; cin >> x;
	    input.push_back(x);
	}

	solve(input);
    }

    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
