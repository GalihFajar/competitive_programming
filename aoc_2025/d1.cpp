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

int mod_cust(int a, int b) {
    return (a % b + b) % b;
}


int parse(string x) {
    if (x[0] == 'L') {
	return -stoi(x.substr(1, x.length() - 1));
    }


    return stoi(x.substr(1, x.length() - 1));
}

int calc(int current, int x) {
    return mod_cust(current + x, 100);
}

int cross(int a, string x) {
    int movt = parse(x);
    int next = calc(a, parse(x));

    if (a == 0 && abs(movt) <= 100) {
	    return 0;
    }

    if (x[0] == 'L') {
	if (abs(movt) <= 100) {
	    if (next >= a && next != 0) {
		return 1;
	    } else {
		return 0;
	    }
	} else {
	    int def_cross = abs(movt / 100);
	    int excess = abs(movt) % 100;
	    int next_excess = calc(a, -excess);

	    
	    if (next_excess > a && a != 0 && next_excess != 0) {
		def_cross++;
	    }

	    return def_cross;
	}
    } else {
	if (abs(movt) <= 100) {
	    if (next <= a && next != 0) {
		return 1;
	    } else {
		return 0;
	    }
	} else {
	    int def_cross = abs(movt / 100);
	    int excess = abs(movt) % 100;
	    int next_excess = calc(a, excess);

	    if (next_excess < a && a != 0 && next_excess != 0) {
		def_cross++;
	    }

	    return def_cross;
	}
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string in; 
    int current = 50;
    int ans = 0;
    int extra_ans = 0;
    while (cin >> in) {
	extra_ans += cross(current, in);
	current = calc(current, parse(in));
	if (current == 0) ans++;
    }

    cout << "#1: ";
    cout << ans << endl;

    cout << "#2: ";
    cout << ans + extra_ans << endl;

    return 0;
}


/*
 *
 *
*/
