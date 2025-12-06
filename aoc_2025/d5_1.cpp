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
using vs = vector<string>;
using ll = long long;


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

vs split(string& s, char delim) {
    vs out;
    stringstream ss(s);

    string t;
    while (getline(ss, t, delim))
	out.push_back(t);

    return out;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    v<pair<ll, ll>> ranges;

    int input_count = 0;
    int ans = 0;
    while (input_count < 2) {
	getline(cin, input);
	if (input.empty()) {
	    input_count++;
	    continue;
	}

	if (input_count == 0) {
	    vs splitted = split(input, '-');
	    ranges.push_back({stoll(splitted[0]), stoll(splitted[1])});
	} else {
	    ll input_ll = stoll(input);
	    for (auto const& x: ranges) {
		if (input_ll >= x.first && input_ll <= x.second) {
		    ans++;
		    break;
		}
	    }
	}
    }
    cout << ans << endl;


    return 0;
}


/*
 *
 *
*/
