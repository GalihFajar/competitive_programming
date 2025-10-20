#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

using vs = vector<string>;
using tiii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi  = vector<vvi>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    int n_ = n;
    vs spotty, plain;

    while (n_--) {
	string s;
	cin >> s;
	spotty.push_back(s);
    }

    n_ = n;

    while (n_--) {
	string s;
	cin >> s;
	plain.push_back(s);
    }

    vector<tiii> to_observes;
    for (int i = 0; i < m; i++) {
	for (int j = i + 1; j < m; j++) {
	    for (int k = j + 1; k < m; k++) {
		to_observes.push_back({i, j, k});
	    }
	}
    }

    int ans = 0;

    vvvi spotty_pairs_idx(256, vvi(256, vi(256)));
    for (auto const& elem: to_observes) {
	int i, j, k;
	vector<tuple<int, int, int>> visited;
	tie(i, j, k) = elem;

	vs spotty_pairs, plain_pairs;
	bool check = true;
	/*unordered_map<string, int> um;*/
	for (int x = 0; x < n; x++) {
	    string& x_spot = spotty[x];

	    if (!spotty_pairs_idx[x_spot[i]][x_spot[j]][x_spot[k]]) {
		spotty_pairs_idx[x_spot[i]][x_spot[j]][x_spot[k]] = 1;
		visited.push_back({x_spot[i], x_spot[j], x_spot[k]});
	    }
	}

	for (int x = 0; x < n; x++) {
	    string& x_plain = plain[x];

	    /*spotty_pairs_idx[x_plain[i]][x_plain[j]][x_spot[k]] = 1;*/
	    if (spotty_pairs_idx[x_plain[i]][x_plain[j]][x_plain[k]]) {
		check = false;
		break;
	    }
	}

	for (auto const& e: visited) {
	    int i, j, k;
	    tie(i, j, k) = e;

	    spotty_pairs_idx[i][j][k] = 0;
	}


	if (check) {
	    ans += check;
	}
    }


    cout << ans << "\n";

    

    return 0;
}
