#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../algo/misc/debug.h"
#else
#define debug(...) 42
#endif

template <typename T> using v = vector<T>;
using ll = long long;
using vll = v<ll>;
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

void print_stack(stack<char> s) {
    v<char> v;

    while (!s.empty()) {
	v.push_back(s.top());
	s.pop();
    }

    reverse(all(v));
    print_v(v);
}

void solve(string& s) {
    stack<char> sc;

    for (int i = 0; i < s.size(); i++) {
	if (sc.empty()) {
	    sc.push(s[i]);
	    continue;
	} 


	if (sc.top() == '(' && s[i] == ')') {
	    sc.pop();
	} else {
	    sc.push(s[i]);
	}
    }
    // cout << "stack: ";
    // print_stack(sc);

    if (sc.empty()) {
	cout << "YES\n"; 
	return;
    }

    if (!sc.empty() && (sc.size() % 2 != 0)) {
	cout << "NO\n";
	return;
    }

    int a = 0, b = 0; // a -> '(' b -> ')'

    while (!sc.empty()) {
	if (sc.top() == '(') a++;
	else b++;

	sc.pop();
    }

    if (a == b) {
	cout << "YES\n";
    } else {
	cout << "NO\n";
    }


    // print_stack(sc);

    // debug(sc);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    
    int tc; cin >> tc;

    for (int i = 0 ; i < tc; i++) {
	int n; cin >> n;
	string s; cin >> s;
	solve(s);
    }

    return 0;
}


/*
 *
 *
*/
