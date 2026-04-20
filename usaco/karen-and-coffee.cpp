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

int const MAX_LIMIT = 2e5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    
    vi temps(MAX_LIMIT + 2);

    int n, k, q;
    cin >> n >> k >> q;

    for (int i = 0; i < n; i++) {
	int a, b;
	cin >> a >> b;

	temps[a]++;
	temps[b+1]--;
    }

    for (int i = 1; i < MAX_LIMIT + 1; i++) {
	temps[i] += temps[i - 1];
    }

    for (int i = 1; i < MAX_LIMIT + 1; i++) {
	if (temps[i] >= k) temps[i] = 1;
	else temps[i] = 0;

	temps[i] += temps[i-1];
    }



    while (q--) {
	int a, b;
	cin >> a >> b;
	cout << temps[b] - temps[a -1] << endl;
    }
    

    return 0;
}


/*
 *
 *
*/
