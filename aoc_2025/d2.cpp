#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <sstream>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;
using vs = v<string>;

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

string repeat(string& s, int t) {
    string ans = "";
    for (int i = 0; i < t; i++) {
	ans += s;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    cin >> input;
    v<pair<string, string>> splitted_pairs;

    vs splitted = split(input, ',');
    for (string &x: splitted) {
	vs temp = split(x, '-');
	splitted_pairs.push_back({temp[0], temp[1]});
    }

    ll second_answer = 0;
    ll first_answer = 0;

    for (auto const &x: splitted_pairs) {
	for (ll a = stoll(x.first); a <= stoll(x.second); a++) {
	    string t = to_string(a);

	    // NOTE: logic for First Problem
	    if (t.substr(0, t.length() / 2) == t.substr(t.length() / 2)) first_answer += a;

	    for (int i = 1; i <= t.length()/2; i++) {
		if (t.length() % i != 0) continue;
		string sub = t.substr(0, i);
		string result = repeat(sub, t.length() / i);

		if (result == t) {
		    second_answer += a;
		    break;
		};
	    }
	}
    }

    cout << "#1: " << first_answer << endl;
    cout << "#2: " << second_answer << endl;

    return 0;
}


/*
 *
 *
*/
