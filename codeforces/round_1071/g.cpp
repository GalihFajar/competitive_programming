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
using vpii = v<pii>;

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

void solve(int n) {
    // find one corner
    pair<int, int> corner_pair = {-1, INT_MIN}; // corner, distance

    vvi answer = vvi(n, vi(n));
    vi p1_distances((n * n) + 1);
    int p1 = 1;

    for (int i = 1; i <= n * n; i++) {
	cout << "? " << p1 << " " << i << endl;
	int x; 
	cin >> x;
	p1_distances[i] = x;

	if (corner_pair.second < x) {
	    corner_pair = {i, x};
	}
    }

    int a = corner_pair.first;
    vi a_distances((n * n) + 1);
    vi s;

    for (int i = 1; i <= n * n; i++) {
	    cout << "? " << a << " " << i << endl;
	    int x; 
	    cin >> x;

	    a_distances[i] = x;
    }

    for (int i = 1; i <= n * n; i++) {
	if (a_distances[i] == n - 1) s.push_back(i);
    }


    // find second corner
    int b;
    vi b_distances((n * n) + 1);
    int max_dist_in_s = -1;

    bool all_same = true;

    int probe = s[0];
    for (int target: s) {
	if (probe == target) continue;

	cout << "? " << probe << " " << target << endl;
	int x; 
	cin >> x;

	if (x > max_dist_in_s) {
	    max_dist_in_s = x;
	    b = target;
	}
    }

    for (int i = 1; i <= n * n; i++) {
	cout << "? " << b << " " << i << endl;
	int x; 
	cin >> x;
	b_distances[i] = x;
    }
    cout << "!" << endl;;

    for (int i = 1; i <= n * n; i++) {
	int r = ((a_distances[i] + b_distances[i]) - n + 1) / 2;
	int c = ((a_distances[i] - b_distances[i]) + n - 1) / 2;
	answer[r][c] = i;
    }

    for (vi& x: answer) {
	print_v(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc; 
    cin >> tc;
    
    while (tc--) {
	int n; 
	cin >> n;
	solve(n);
    }

    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
