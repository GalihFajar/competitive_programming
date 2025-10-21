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

int check_type(vi& v, int i) {
    int n = v.size();

    if (i >= n || (i + 1) >= n || (i + 2) >= n) {
	return -1; // unknown type
    }

    int a = v[i], b = v[i + 1], c = v[i + 2];

    if ((a < b && b > c && a > c && (c - (b - a) > 0))) {
	return 1
    } else if (....) {
	....
	return 2
    }


    return 0; // invalid type
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    //
    return 0;
}


/*
 *
 *
 *
 */
