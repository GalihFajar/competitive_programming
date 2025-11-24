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

vi dp(101, -1);
unordered_map<string, bool> visited;

int calc(int x) {
    int ans = 0;
    int number_of_twos = x / 2;
    ans += x % 2 == 0 ? 1 : 0;

    ans += number_of_twos / 2;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    int n; cin >> n;
    vi input;
    while (n--) {
	int x; cin >> x;
	if (x % 2 != 0) cout << 0 << endl;
	else 
	    cout << calc(x) << endl;
    }

    return 0;
}


/*
 *
 *
*/
