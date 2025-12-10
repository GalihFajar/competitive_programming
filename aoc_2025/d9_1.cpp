#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;
using vll = v<ll>;
using pll = pair<ll, ll>;

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
void print_v_pair(vector<T>& v) {
    for (auto const& elem: v) {
	cout << '{' << elem.first << "," << elem.second << "} ";
    }
    cout << endl;
}




ll calc_area(pll a, pll b) {
    return (abs(a.first - b.first) + 1) * (abs(a.second - b.second) + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    
    string s; 
    v<pll> inputs;

    while (cin >> s) {
	stringstream ss(s);
	string t;
	vll p;
	while (getline(ss, t, ',')) {
	    p.push_back(stoll(t));
	}

	inputs.push_back({p[0], p[1]});
    }

    ll ans = INT_MIN;
    for (int i = 0; i < inputs.size(); i++) {
	for (int j = i; j < inputs.size(); j++) {
	    ans = max(ans, calc_area(inputs[i], inputs[j]));
	}
    }

    cout << ans << endl;

    return 0;
}


/*
 *
 *
*/
