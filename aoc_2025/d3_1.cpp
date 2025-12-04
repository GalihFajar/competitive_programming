#include <iostream>
#include <string>
#include <vector>
#include <climits>
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

int to_int(char c) {
    return c - '0';
}

int calculate(string& s) {
    vi prefix;
    vi suffix;

    prefix.push_back(to_int(s[0]));
    suffix.push_back(to_int(s.back()));

    // build prefix
    for (int i = 1; i < s.size(); i++) {
	prefix.push_back(max(to_int(s[i]), prefix.back()));
    }

    // build suffix
    for (int i = s.size() - 2; i >= 0; i--) {
	suffix.push_back(max(to_int(s[i]), suffix.back()));
    }
    reverse(all(suffix));

    int ans = INT_MIN;
    for (int i = 0; i < s.size() - 1; i++) {
	ans = max(ans, prefix[i] * 10 + suffix[i + 1]);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string in;
    int ans = 0;
    while (cin >> in) {
	ans += calculate(in);
    }
    
    cout << ans << endl;

    return 0;
}


/*
 * Using prefix sum approach
 *
 *
*/
