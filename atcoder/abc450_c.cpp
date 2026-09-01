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
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

bool is_out_of_bound(v<string>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= (int) grid.size() || j >= (int) grid[0].size()) {
	return true;
    }

    return false;
}

const v<pair<int, int>> MOVT = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


int dfs(v<string>& grid, int i, int j) {
    if (is_out_of_bound(grid, i, j)) {
	return 0;
    }

    if (grid[i][j] != '.') return 0;


    for (const pii& x: MOVT) {
	grid[i][j] = '#';
	dfs(grid, i + x.first, j + x.second);
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    // fio("<filename_prefix>")
    //
    //
    int h, w; cin >> h >> w;
    vector<string> grid;
    string temp;

    while (cin >> temp) {
	grid.push_back(temp);
    }
    debug(grid);



    // check edge
    for (int i = 0; i < (int) grid.size(); i++) {
	dfs(grid, i, 0);
	dfs(grid, i, grid[0].size() - 1);
    }

    for (int j = 0; j < (int) grid[0].size(); j++) {
	dfs(grid, 0, j);
	dfs(grid, grid.size() - 1, j);
    }

    int total = 0;

    for (int i = 0; i < (int) grid.size(); i++) {
	for (int j = 0; j < (int) grid[0].size(); j++) {
	    total += dfs(grid, i, j);
	}
    }

    cout << total << endl;

    return 0;
}


/*
 *
 *
*/
