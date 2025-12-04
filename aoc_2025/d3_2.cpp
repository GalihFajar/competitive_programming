#include <cstdlib>
#include <iostream>
#include <string>
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
using vs = v<string>;
using vvs = v<vs>;

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

int to_int(char c) {
    return c - '0';
}

int calculate(string& s) {
    return 0;
}

vvs dp;

string search(string& input, string current_string, int curr, int rem) {
    if (curr >= input.size() || rem == 0) {
	return "";
    }

    if (dp[curr][rem] != "") {
	return dp[curr][rem];
    }

    string choose = current_string + input[curr] + search(input, current_string, curr + 1, rem - 1);
    string skip = current_string + search(input, current_string, curr + 1, rem);

    ll choose_ll = 0, skip_ll = 0;

    if (choose.size() > 0)
	choose_ll = stoll(choose);
    if (skip.size() > 0)
	skip_ll = stoll(skip);


    if (choose_ll >= skip_ll) {
	dp[curr][rem] = choose;
    } else {
	dp[curr][rem] = skip;
    }


    return dp[curr][rem];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string in;
    ll ans = 0;
    while (cin >> in) {
	dp = vvs(in.size(), vs(13, ""));

	// set rem to 2 for the first part of problem
	ans += stoll(search(in, "", 0, 12));
    }
    
    cout << ans << endl;

    return 0;
}


/*
 * Prefix sum doesnt work here -> go for dp approach
 * This dp approach is generic, would work for first part of problem
 *
*/
