#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <queue>
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

char get_color(int d) {
    int rem = d % 3;
    if (rem == 1) return 'g';
    if (rem == 2) return 'b';

    return 'r';
}


int get_nearest_neighbor(string neighbors) {
    bool has_red = false, has_blue = false, has_green = false;
    char v_color = 'x';

    for (auto const& c: neighbors) {
	if (c == 'r') has_red = true;
	else if (c == 'g') has_green = true;
	else if (c == 'b') has_blue = true;
    }

    if (has_red && has_green) {
	v_color = 'g';
    } else if (has_red && has_blue) {
	v_color = 'r';
    } else if (has_blue && has_green) {
	v_color = 'b';
    } else {
	if (has_red) v_color = 'r';
	else if (has_green) v_color = 'g';
	else if (has_blue) v_color = 'b';
    }

    for (int i = 0; i < neighbors.size(); i++) {
	if (neighbors[i] == v_color) return i + 1;
    }

    return -1;
}

void process_first() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
	int a, b; cin >> a >> b;
	vvi edges = vvi(a + 1);
	v<char> colors(a + 1);
	v<bool> visited(a + 1);

	while (b--) {
	    int x, y; cin >> x >> y;
	    edges[x].push_back(y);
	    edges[y].push_back(x);
	}

	// run bfs
	queue<pair<int, int>> s; // {vertex, distance}
	s.push({1, 0});
	int distance = 1;
	while (!s.empty()) {
	    pair<int, int> current = s.front(); s.pop();
	    if (visited[current.first]) continue;
	    visited[current.first] = true;
	    colors[current.first] = get_color(current.second);

	    for (auto const& nei: edges[current.first]) {
		s.push({nei, current.second + 1});
	    }
	}

	for (int i = 1; i < colors.size(); i++) {
	    cout << colors[i];
	}
	cout << '\n';
    }
}

void process_second() {
    int n; cin >> n;

    while (n--) {
	int tc; cin >> tc;

	while (tc--) {
	    int a; cin >> a;
	    string s; cin >> s;
	    cout << get_nearest_neighbor(s) << endl;
	}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string command;

    if (cin >> command) {
	if (command == "first") {
	    process_first();
	} else {
	    process_second();
	}
    }

    // fio("<filename_prefix>")
    

    return 0;
}


/*
 *
 *
*/
