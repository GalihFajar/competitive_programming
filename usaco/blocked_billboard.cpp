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

int intersect(Rect p, Rect q) {
    int x_overlap = max(0, (min(p.x2, q.x2) - max(p.x1, q.x1)));
    int y_overlap = max(0, (min(p.y2, q.y2) - max(p.y1, q.y1)));
    return x_overlap * y_overlap;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fio("billboard")
    Rect p, q, r;
    p.read(); q.read(); r.read();

    cout << p.area() + q.area() - intersect(p, r) - intersect(q, r) << endl;


    

    return 0;
}


/*
 * Simulation is doable but using math probably faster
 * One thing to note here is that a truck is impossible to be suspended, it has to be on the ground. This simplifies calculation by much.
 *
*/
