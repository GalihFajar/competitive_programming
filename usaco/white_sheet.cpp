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
using ll = long long;

#define all(x) begin(x), end(x)
#define fio(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout);

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

struct Rect {
    int x1, y1, x2, y2;
    Rect() {

    }

    Rect(int x1, int y1, int x2, int y2) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
    }

    void read() {cin >> x1 >> y1 >> x2 >> y2;};
    ll area() {return (ll) (x2 - x1) * (y2 - y1);};
    void print_coord() {
	printf("x1, y1: (%d, %d)\n", x1, y1);
	printf("x2, y2: (%d, %d)\n", x2, y2);
    }
};

Rect get_overlaps_rect(Rect p, Rect q) {
    int o_x2 = min(p.x2, q.x2), o_x1 = max(p.x1, q.x1);
    int o_y2 = min(p.y2, q.y2), o_y1 = max(p.y1, q.y1);

    return Rect(o_x1, o_y1, o_x2, o_y2);
}

ll intersect_area(Rect p, Rect q) {
    Rect o = get_overlaps_rect(p, q);

    return (ll) max(0, (o.x2 - o.x1)) * max(0, (o.y2 - o.y1));
}

ll intersect_area(Rect p, Rect q, Rect r) {
    auto o = get_overlaps_rect(q, r);

    return intersect_area(p, o);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    Rect p, q, r;
    p.read(); q.read(); r.read();
    ll white_area_left = p.area() - (intersect_area(p, q) + intersect_area(p, r)) + intersect_area(p, q, r);

    if (!white_area_left) {
	cout << "NO\n";
    } else {
	cout << "YES\n";
    }
    

    return 0;
}


/*
 *
 *
*/
