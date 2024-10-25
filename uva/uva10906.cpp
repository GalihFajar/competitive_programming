#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;


typedef struct expr {
    char op;
    string s;
} expr;

typedef unordered_map<string, expr> umse;

umse m;


expr get_expr(string& s) {
    if (m.count(s)) {
        return m[s];
    }

    expr e = {'&', s};

    return e;
}

void solve(string& a, string& b, char op, string& c) {
    expr na = get_expr(a), nb = get_expr(b), nc;
    nc.op = op;

    if (na.op == '+' && op == '*') {
        nc.s += "(" + na.s + ")";
    } else {
        nc.s += na.s;
    }

    nc.s += op;

    if (nb.op == '+' || (nb.op == '*' && op == '*')) {
        nc.s += "(" + nb.s + ")";
    } else {
        nc.s += nb.s;
    }

    m[c] = nc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    string last;
    int cnt = 1;
    while (tc--) {
        int t; cin >> t;
        string a, b, c; char temp_, op;
        m.clear();
        while (t--) {
            cin >> c >> temp_ >> a >> op >> b;
            last = c;
            solve(a, b, op, c);
        }

        cout << "Expression " << "#" << cnt++ << ": " << m[c].s << "\n";
    }

    return 0;
}
