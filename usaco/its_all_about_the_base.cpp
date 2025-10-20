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

long long calc_with_base(string& s, int base) {
    int len = s.size();
    long long total = 0;
    for (const char& c: s) {
	total += pow(base, len - 1) * (c - '0');
	len--;
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fio("whatbase")
    int k; cin >> k;
    for (int i = 0 ;i < k; i++) {
	string a, b; cin >> a >> b;
	long long x = 10, y = 10;
	long long a_yield = calc_with_base(a, x), b_yield = calc_with_base(b, y);
       while (a_yield != b_yield) {
	    if (a_yield < b_yield) {
		x++;
		a_yield = calc_with_base(a, x);
	    } else {
		y++;
		b_yield = calc_with_base(b, y);
	    }
       }

	cout << x << " " << y << endl;

    }

    return 0;
}


/*
 *
 * the idea is to check all of the possibilities (iterating through all)
 * it should be fast enough since for each case, we only need to search on 15k + 15k
 * the only problem is that the bound for k is not defined, so we can only guess
 * lets implement directly
 * AC
 *
*/
