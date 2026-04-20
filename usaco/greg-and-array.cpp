#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using ll = long long;
using vll = vector<long long>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define fio(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout);
#define psp(x) cout << x << " ";
#define pnl(x) cout << x << "\n";
#define for_ex(beg, n) for(int i = beg; i < n; i++)

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

class Op {
    public: 
	Op () {}
	Op (int a, int b, int c) {
	    this -> a = a;
	    this -> b = b;
	    this -> c = c;
	}
	int a, b, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vll a(n + 2);
    vll s(m + 2);
    vll add(n + 2);

    for_ex(1, n + 1) {
	cin >> a[i];
    }

    v<Op> ops(m + 1);

    for_ex(1, m + 1) {
	int a, b, c;

	cin >> a >> b >> c;

	ops[i] = Op(a, b, c);
    }

    for_ex(1, k + 1) {
	int a, b;
	cin >> a >> b;

	s[a]++;
	s[b+1]--;
    }

    for_ex(1, m+1) {
	s[i] += s[i-1];

	add[ops[i].a] += ops[i].c * s[i];
	add[ops[i].b+1] -= ops[i].c * s[i];
    }

    for_ex(1, n + 1) {
	add[i] += add[i - 1];

	cout << add[i] + a[i] << " ";
    }

    cout << endl;



    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
