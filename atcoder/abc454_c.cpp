#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

#ifdef LOCAL
#include "../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

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

    int n, m;
    cin >> n >> m;

    vvi adj_list(n + 1);
    unordered_set<int> visited;

    for (int i = 0; i < m; i++) {
	int a, b; cin >> a >> b;
	adj_list[a].push_back(b);
    }

    debug(adj_list);


    queue<int> q;
    q.push(1);

    while (!q.empty()) {
	int a = q.front(); q.pop();
	if (visited.find(a) != visited.end()) {
	    continue;
	}
	visited.insert(a);

	for (auto const& b: adj_list[a]) {
	    q.push(b);
	}
    }

    cout << (int) visited.size() << endl;

    return 0;
}


/*
 *
 *
*/
