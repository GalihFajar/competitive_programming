#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vll a(n + 2);

    for (int i = 1; i <= n; i++) {
	 cin >> a[i];
    }

    vll count(n + 2);

    while (q--) {
	int a, b;
	cin >> a >> b;

	count[a]++;
	count[b+1]--;
    }

    for (int i = 1; i < n + 2; i++) {
	count[i] += count[i - 1];
    }

    sort(all(count));
    sort(all(a));

    ll ans = 0;
    for (int i = 1; i < n + 2; i++) {
	ans += (count[i] * a[i]);
    }

    cout << ans << endl;


    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
