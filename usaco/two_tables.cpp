#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
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

struct Rect {
    int x1, y1, x2, y2;
    Rect() {}
    Rect(int x1, int y1, int x2, int y2) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
    }
    void read() {cin >> x1 >> y1 >> x2 >> y2;};
    int width() {return x2 - x1;};
    int height() {return y2 - y1;};
};

int min_excess_w(int w, Rect r) {
    return min(r.x1, w - r.x2);
}

int max_excess_w(int w, Rect r) {
    return max(r.x1, w - r.x2);
}

int min_excess_h(int h, Rect r) {
    return min(r.y1, h - r.y2);
}

int max_excess_h(int h, Rect r) {
    return max(r.y1, h - r.y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
	int w, h; cin >> w >> h;
	Rect table_1; table_1.read();
	int a, b; cin >> a >> b;
	Rect table_2 = Rect(0, 0, a, b);
	
	int table_1_w = table_1.width();
	int table_1_h = table_1.height();

	int table_2_w = table_2.width();
	int table_2_h = table_2.height();
	int min_ans = INT_MAX;

	if (table_1_w + table_2_w <= w) {
	    int excess_left = table_1.x1;
	    int excess_right = w - table_1.x2;
	    int dist_need_to_cover_left = excess_left >= table_2_w ? 0 : table_2_w - excess_left;
	    int dist_need_to_cover_right = excess_right >= table_2_w ? 0 : table_2_w - excess_right;

	    if (table_2_h > h) {
	    } else {
		min_ans = min(min_ans, dist_need_to_cover_left);
		min_ans = min(min_ans, dist_need_to_cover_right);
	    }
	} 

	if (table_1_h + table_2_h <= h) {
	    int excess_down = table_1.y1;
	    int excess_up = h - table_1.y2;
	    int dist_need_to_cover_down = excess_down >= table_2_h ? 0 : table_2_h - excess_down;
	    int dist_need_to_cover_up = excess_up >= table_2_h ? 0 : table_2_h - excess_up;
	    
	    if (table_2_w > w) {
	    } else {
		min_ans = min(min_ans, dist_need_to_cover_up);
		min_ans = min(min_ans, dist_need_to_cover_down);
	    }
	}   

	if (min_ans < INT_MAX) {
	    float ans = (float) min_ans;
	    cout << fixed << setprecision(9) << ans << endl;
	} else {
	    cout << "-1\n";
	}

    }
    

    return 0;
}


/*
 * seems like we only need to know how much x and y is intersecting, and choose based on possibilities, then by shortest distance
 * since it doesn't matter where it is, we then can calculate whether the new coordinate (x1 + x2), (y1 + y2) is bigger than actual the room width/length
 * Let's  implement
 * Wait or we can just calculate without knowning the intersection? Should be
 * Findings: the table would either move vertically or horizontally but not both at the same time
 * Why? Since the new table would intersect, but can "escape" in x or y direction 
 * Both directions would be suboptimal, since it would constructed of two directions
 * Implementing...
 * WA
 * The excess logic is already cool, but seems to complex to debug
 * AC
*/
