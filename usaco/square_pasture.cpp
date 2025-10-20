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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fio("square")
    Rect p, q;
    p.read(); q.read();

    int length = max(p.x2, q.x2) - min(p.x1, q.x1);
    int width = max(p.y2, q.y2) - min(p.y1, q.y1);
    int sq = max(length, width);
    sq *= sq;

    cout << sq << endl;
    

    return 0;
}


/*
 * The idea is probably simple, search for the max between length and width then square it.
 * We need to have the max of x - min of x to get the length, vice versa for width
 * Since one is on the bottom left and the other is on the top right, the bottom left value must be < top right, so we need to compare bottom left with bottom left for min, and top right with top right for max
 * After we get the max between width and length, we squar it due to the pasture being a square
 * AC
 *
*/
