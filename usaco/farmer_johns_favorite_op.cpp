
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
using ll = long long;
using vll = v<ll>;

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

template <typename T>
void print_v_range(vector<T>& v, int a, int b) {
    for (int i = a; i <= b; i++) {
	int elem = v[i];
	cout << elem << " ";

    }
    cout << endl;
}

template <typename T>
T sum_range(v<T>& v, int beg_idx, int end_idx) {
    return [&]() -> T {T ret = 0; for (int i = beg_idx; i <= end_idx; i++) ret += v[i]; return ret;}();
}

ll get_sum(vll& pref, int L, int R) {
    if (L > R) return 0; // Handle empty ranges safely
    
    ll sub = (L == 0) ? 0 : pref[L - 1];
    return pref[R] - sub;
}

ll calc_with_pref(vll& pref, int beg_idx, int end_idx) {
    int size = (end_idx - beg_idx) + 1;
    int half = size / 2;

    ll left = get_sum(pref, beg_idx, beg_idx + half - 1);
    
    ll right = get_sum(pref, end_idx - half + 1, end_idx);

    return right - left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")

    int tc; cin >> tc; 
    while (tc--) {
	int n, m; cin >> n >> m;
	vll vec;
	for (int i = 0; i < n; i++) {
	    int x; cin >> x;
	    vec.push_back(x % m);
	}
	sort(all(vec));

	for (int i = 0; i < n; i++) {
	    vec.push_back(((ll) vec[i]) + m);
	}

	vll prefix = vll(n * 2);
	prefix[0]  = vec[0];
	for (int i = 1; i < prefix.size(); i++) {
	    prefix[i] = (ll) vec[i] + prefix[i-1];
	}

	ll ans = LLONG_MAX;
	for (int i = 0; i < vec.size() && i + n - 1 <= vec.size() - 1; i++) {
	    int j = i + n - 1;
	    ans = min(ans, calc_with_pref(prefix, i, j));
	}

	cout << ans << endl;
    }

    return 0;
}


/*
 *
 *
*/
