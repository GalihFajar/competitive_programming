#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vs = v<string>;

#define all(x) begin(x), end(x)

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

vs COWS = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy","Sue"};

int resolve_idx(string& s) {
    for (int i = 0; i < COWS.size(); i++) {
	if (s == COWS[i]) return i;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    sort(all(COWS));
    vvi graph = vvi(COWS.size());

    while (n--) {
	string cow_1, _a, _b, _c, _d, cow_2;
	cin >> cow_1 >> _a >> _b >> _c >> _d >> cow_2;
	int idx_c1 = resolve_idx(cow_1);
	int idx_c2 = resolve_idx(cow_2);

	graph[idx_c1].push_back(idx_c2);
	graph[idx_c2].push_back(idx_c1);

	sort(all(graph[idx_c1]));
	sort(all(graph[idx_c2]));
    }

    v<bool> processed = v<bool>(COWS.size());
    queue<int> q;

    for (int i = 0; i < graph.size(); i++) {
	q.push(i);
	for (int j = 0; j < graph[i].size(); j++) {
	    q.push(graph[i][j]);
	}
    }

    while (!q.empty()) {
	int idx_to_print = q.front();
	q.pop();
	if (processed[idx_to_print]) continue;
	processed[idx_to_print] = true;
	cout << COWS[idx_to_print] << endl;
    }

    
    /*freopen("<FILENAME>.in", "r", stdin); */
    /*freopen("<FILENAME>.out", "w", stdout);*/

    return 0;
}


/*
 *
 *
*/
