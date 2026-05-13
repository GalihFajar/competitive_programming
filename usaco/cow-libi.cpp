#include <bits/stdc++.h>
using namespace std;

#define int long long

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

struct Event {
    int t, x, y;

    bool operator<(const Event& other) const{return t < other.t;};
};

Event read() {
    int x, y, t;
    cin >> x >> y >> t;
    return {t, x, y};
}

bool reachable(const Event& a, const Event& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int dt = a.t - b.t;

    return dx * dx + dy * dy <= dt * dt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")

    int g, n; cin >> g >> n;
    v<Event> graze(g);

    for (int i = 0; i < g; i++) {
	graze[i] = read();
    }

    sort(all(graze));

    int ans = 0;
    for (int i = 0; i < n; i++) {
	Event alibi = read();

	int pos = upper_bound(all(graze), alibi) - graze.begin();

	int innocent = false;
	for (int y = pos - 1; y <= pos; y++) {
	    if (y >= 0 && y < g) innocent |= !reachable(graze[y], alibi);
	}

	ans += innocent;
    }

    cout << ans << endl;


    return 0;
}


/*
 *
 *
*/
