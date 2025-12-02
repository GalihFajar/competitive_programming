#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <stack>
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

vi prefix(vi& vec) {
    vi out(vec.size());
    out[0] = vec[0];
    for (int i = 1; i < vec.size(); i++) {
	out[i] = min(vec[i - 1], out[i - 1]);
    }

    return out;
}

vi suffix(vi& vec) {
    vi out(vec.size());
    out[vec.size() - 1] = vec[vec.size() - 1];

    for (int i = vec.size() - 2; i >= 0; i--) {
	out[i] = max(vec[i + 1], out[i + 1]);
    }

    return out;
}

bool is_valid_tree(vi& in) {
    vi pref = prefix(in);
    vi suf = suffix(in);

    for (int i = 0; i < suf.size(); i++) {
	if (suf[i] <= pref[i]) {
	    return false;
	}
    }

    return true;
}

void print_tree(vi& in) {
    stack<int> s;
    vi suff = suffix(in);
    vi pref = prefix(in);
    vi suffix_maxes_idx;

    int current_max = in.back();
    int latest_idx = in.size() - 1;
    for (int i = in.size() - 2; i >= 0; i--) {
	if (in[i] > current_max) {
	    suffix_maxes_idx.push_back(latest_idx);
	    current_max = in[i];
	    latest_idx = i;
	}

	if (i == 0) {
	    if (suffix_maxes_idx.empty() || suffix_maxes_idx.back() != latest_idx) {
		suffix_maxes_idx.push_back(latest_idx);
	    }
	}
    }

    reverse(all(suffix_maxes_idx));



    int beg = 0;
    bool first = true;
    unordered_map<string, bool> visited;
    int prev_x;
    for (auto x: suffix_maxes_idx) {
	for (int i = beg; i < x; i++) {
	    cout << in[x] << " " << in[i] << endl;;
	    string s;
	    s += to_string(in[x]);
	    s += '#';
	    s += to_string(in[i]);
	    visited[s] = true;
	}
	beg = x + 1;

	if (!first) {
	    string s;
	    s += to_string(in[x]);
	    s += '#';
	    s += to_string(pref[prev_x]);

	    if (!visited[s])
		cout << in[x] << " " << pref[prev_x] << endl;

	    visited[s] = true;
	}

	prev_x = x;

	first = false;
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")

    int tc; cin >> tc;
    while (tc--) {
	int n; cin >> n;
	vi inp(n);
	for (int i = 0; i < n; i++) {
	    cin >> inp[i];
	}

	if (!is_valid_tree(inp)) {
	    cout << "No\n";
	} else {
	    cout << "Yes\n";
	    print_tree(inp);
	}
    }

    return 0;
}


/*
 * Ok lets ask llm for hints
 * it turns out it would involve prefix & suffix "sum"
 * Lets figure out ourselves how that might play
 * I think I got it, instead of checking the tree is possible or not, we should check if there's any violation that makes the tree impossible
 * Using prefix, we construct the minimal value, so prefix[n] is minimal value up until point n [0...n]
 * Using suffix, its basically the same but we construct max value, so suffix[n] is max value [N...n]
 * The idea is, if theres violation, we then cannot construct the tree
 * The violation is defined as whether we cannot connect any point from suffix (the max value) to suffix (any min value)
 * Because at point suffix[n], if its impossible to connect, then suffix[n+1] cannot connect as well (suffix[n] > suffix[n + 1])
 * We can define violation if prefix[n] >= suffix[n]
 * The '=' is there because it means that the point can only connect to itself
 *
 *
*/
