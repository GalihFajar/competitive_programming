#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

template <typename T> using v = vector<T>;
using ll = long long;
using vll = vector<ll>;
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

int const MAX_LEN = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")

    int n, k;
    cin >> n >> k;

    vll haybales(n + 1, 0);

    while (k--) {
	int a, b;
	cin >> a >> b;

	haybales[a]++;
	haybales[b+1]--;
    }

    for (int i = 1; i <= n; i++) {
	haybales[i] += haybales[i-1];
    }

    sort(all(haybales));

    cout << haybales[(n/2) + 1] << endl;

    return 0;
}


/*
 *
 *
*/
