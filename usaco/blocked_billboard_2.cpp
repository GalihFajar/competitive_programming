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

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}


struct Rect {
    int x1, y1, x2, y2;
    void read() {cin >> x1 >> y1 >> x2 >> y2;};
    int area() {return (x2 - x1) * (y2 - y1);};
};

// bl_a_x >= tr_b_x || tr_a_x <= bl_b_x || bl_a_y >= tr_b_y || tr_a_y <= bl_b_y
// p.x1 >= q.x2 || p.x2 <= q.x1 || p.y1 >= q.y2 || p.y2 <= q.y1
bool is_intersect(Rect p, Rect q) {
    if (p.y1 > q.y2 || p.y2 < q.y1 || p.x1 > q.x2 || p.x2 < q.x1) {
	return false;
    }

    return true;
}

int intersect_area(Rect p, Rect q) {
    int x_overlap = max(0, (min(p.x2, q.x2) - max(p.x1, q.x1)));
    int y_overlap = max(0, (min(p.y2, q.y2) - max(p.y1, q.y1)));
    /*printf("x_overlap: %d, y_overlap: %d\n", x_overlap, y_overlap);*/
    return x_overlap * y_overlap;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fio("billboard")
    Rect p, q;
    p.read(); q.read();

    if (!is_intersect(p, q)) {
	cout << p.area() << endl;
    } else {
	if ((q.x1 > p.x1 && q.x2 < p.x2) || (q.y1 > p.y1 && q.y2 < p.y2)) {
	    cout << p.area() << endl;

	} else if ((q.x1 <= p.x1 && q.x2 >= p.x2) || (q.y1 <= p.y1 && q.y2 >= p.y2)) {
	    // calculate intersecting area
	    cout << max(0, (p.area() - intersect_area(p, q))) << endl;
	} else {
	    cout << p.area() << endl;
	}
    }

    

    return 0;
}


/*
 * forgot the vertical case, implementing...
 * Almost! there is an edge case left, so what would it be??
 * Let's try if the billboard is in the middle but intersecting, the tarp should full cover anyways
 * Not working!
 * Hmm can the billboard suspended in the air? It's like the case where it intersects in the middle, but between y points
 * wtf it can
 * AC
*/
