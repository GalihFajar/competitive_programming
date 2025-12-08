#include <iostream>
#include <vector>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long>;
using vvll = v<vll>;
using pii = pair<int, int>;
using vs = v<string>;
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

int total_split = 0;
vvll dp;

ll dfs(vs& input, int i, int j) {
    ll total = 0;
    if (i < 0 || j < 0 || i >= input.size() || j >= input[i].size()) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    if (input[i][j] == '.' || input[i][j] == 'S') {
	total += dfs(input, i + 1, j);
    } else if (input[i][j] == '^') {
	total += dfs(input, i, j + 1) + dfs(input, i, j - 1);
    }
    dp[i][j] = total;

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    vs input;
    string s;
    while (cin >> s) {
	input.push_back(s);
    }

    pii start;
    for (int i = 0; i < input[0].size(); i++) {
	if (input[0][i] == 'S') start = {0, i};
    }
    dp = vvll(input.size(), vll(input[0].size(), -1));

    ll ans = dfs(input, start.first, start.second);

    cout << ans << endl;


    return 0;
}


/*
 *
 *
*/
