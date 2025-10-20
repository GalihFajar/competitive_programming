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

    // fio("<filename_prefix>")
    int tc; cin >> tc;
    for (int j = 0; j < tc; j++) {
	string s; cin >> s;
	s += 'X';

	int total_a, b_starters;
	int run_len;
	vi a_runs;
	char last;

	last = s[0];
	run_len = 1;
	b_starters = 0, total_a = 0;

	for (int i = 1; i < s.size(); i++) {
	    if (s[i] != last) {
		if (last == 'A') {
		    total_a += run_len;
		    a_runs.push_back(run_len);
		} else if (last == 'B') {
		    b_starters += min(run_len, 2); // if ABBBBBBBA only each end of B can trigger reaction, hence the max is two
		}

		run_len = 0;
	    }

	    run_len++;
	    last = s[i];
	}

	if (b_starters < a_runs.size()) {
	    int exclude = *min_element(a_runs.begin(), a_runs.end());
	    cout << total_a - exclude << endl;
	} else {
	    cout << total_a << endl;
	}

    }
    

    return 0;
}


/*
 *
 * lets greedy this and check ba to right and ab to left
 * ok it doesn't work
 * lets see hints
 * so the idea here is to check the chain of As and where B could eat those As
 * at all cases, all Bs can eat all As as long as it's adjacent
 *
*/
