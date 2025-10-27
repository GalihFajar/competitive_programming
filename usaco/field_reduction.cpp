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
using vpii = v<pii>;

#define all(x) begin(x), end(x)
#define fio(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout);
#define psp(x) cout << x << " ";
#define pnl(x) cout << x << "\n";

float calc_r(pii& a) {
    return sqrt(pow(a.first, 2) + pow(a.second, 2));
}

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

template <typename K, typename T>
void print_v(vector<pair<K, T>>& v) {
    for (auto const& elem: v) {
	cout << "{"  << elem.first << ", " << elem.second << "} ";
    }
    cout << endl;
}

int calc_area(pii& a, pii& b) {
    int temp =  abs(a.first - b.first) * abs(a.second - b.second);
    printf("{%d, %d}; {%d, %d}\n", a.first, a.second, b.first, b.second);
    cout << temp << endl;
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    fio("reduce");

    int n; cin >> n;
    vpii input;
    for (int _x = 0; _x < n; _x++) {
	int a, b; cin >> a >> b;
	input.push_back({a, b,});
    }

    vpii sorted_x = input;
    vpii sorted_y = input;

    sort(all(sorted_x), [](pii& a, pii& b) -> bool {
	return a.first < b.first;
    });

    sort(all(sorted_y), [](pii& a, pii& b) -> bool {
	return a.second < b.second;
    });

    vi x_min = {sorted_x[0].first, sorted_x[1].first, sorted_x[2].first, sorted_x[3].first};
    vi x_max = {sorted_x[n-1].first, sorted_x[n-2].first, sorted_x[n-3].first, sorted_x[n-4].first};

    vi y_min = {sorted_y[0].second, sorted_y[1].second, sorted_y[2].second, sorted_y[3].second};
    vi y_max = {sorted_y[n-1].second, sorted_y[n-2].second, sorted_y[n-3].second, sorted_y[n-4].second};

    int ans = INT_MAX;

    for (auto xmi: x_min) {
	for (auto xma: x_max) {
	    for (auto ymi: y_min) {
		for (auto yma: y_max) {
		    if (xmi >= xma || ymi >= yma) continue;
		    int removed = 0;
		    for (auto& p: input) {
			if (p.first < xmi || p.first > xma || p.second < ymi || p.second > yma) {
			    removed++;
			}
		    }
		    if (removed > 3) continue;
		    ans = min(ans, abs(xmi - xma) * abs(ymi - yma));
		}
	    }
	}
    }

    cout << ans << endl;


    return 0;
}


/*
 *
 * 3 front 0 backs
 * 2 front 1 backs
 * 1 front 2 backs
 * 0 front 3 backs
 * ok the intuition is kinda correct, but misses something
 * lets see hints
 * so the rectangle coordinates is strictly affected by the location of cows, since cows are allowed on the edge
 * now if we want to exclude cows, it could only be on each end, or both.
 * removing cows in the middle is impossible since there would be two fences if the answer is possible
 * from that, we need to choose for points: x max, x min, y max and y min.
 * since those points must be where the cows sit, so we could exclude case by case
 * it seems like awfully lots of combinations, but since we're limited to three AND from analysis we could only remove cows on the ends, the possibilities is not so much, that is 4^4
 * so the focus here is to remove the cows, but by removing, we don't necesesarily remove both points, we could remove 1 point and use the other.
 *
*/
