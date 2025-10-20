#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

template <typename T> 
void print_vector(vector<T>& v) {
    for (auto const& e: v) {
	cout << e << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("balancing.in", "r", stdin); 
    freopen("balancing.out", "w", stdout);

    int n, b; cin >> n >> b;
    vi x_count(b, 0), y_count(b, 0);
    vvi yx_list(b);
    vi x_list, y_list;
    int n_ = n;


    while (n_--) {
	int x, y;
	cin >> x >> y;
	if (!y_count[y]) {
	    y_list.push_back(y);
	}

	if (!x_count[x]) {
	    x_list.push_back(x);
	}

	y_count[y]++;
	x_count[x]++;
	yx_list[y].push_back(x);
    }
    /*cout << "x list: "; print_vector(x_list);*/
    /*cout << "y_list: "; print_vector(y_list);*/
    /*cout << "x_list: "; print_vector(x_list);*/

    sort(y_list.begin(), y_list.end());
    sort(x_list.begin(), x_list.end());


    pair<int, vector<int>> y_candidate = {INT_MAX, {}}; // <size, y>
    for (int i = 0; i < y_list.size(); i++) {
	// count that is less than equal to
	int total_under = 0;
	for (int j = 0; j <= i; j++) {
	    total_under += y_count[y_list[i]];
	}
	int total_upper = n - total_under;
	int diff = abs(total_under-total_upper);

	if (abs(diff) < y_candidate.first) {
	    y_candidate = {diff, {y_list[i]}};
	} else if (diff == y_candidate.first) {
	    y_candidate.second.push_back(y_list[i]);
	}
    }

    /*cout << "diff: " << y_candidate.first << endl;*/
    /*print_vector(y_candidate.second);*/

    int ans = INT_MAX;
    for (int i = 0; i < x_list.size(); i++) {
	int x = x_list[i];
	for (auto const& y: y_list) {
	    /*cout << "y=" << y  << " x=" << x << endl;*/
	    int up_left = 0, up_right = 0, down_left = 0, down_right = 0;
	    for (auto const& y_curr: y_list) {
		if (y_curr <= y) {
		    for (auto const& x_curr: yx_list[y_curr]) {
			/*printf("down current: %d, %d, x = %d, y = %d\n", curr_x, y_curr, x, y);*/
			down_left += x_curr <= x;
			down_right += x_curr > x;
		    }
		} else {
		    for (auto const& x_curr: yx_list[y_curr]) {
			/*printf("up current: %d, %d, x = %d, y = %d\n", curr_x, y_curr, x, y);*/
			up_left += x_curr <= x;
			up_right += x_curr > x;
		    }
		}
	    }
	    /*printf("up left: %d, up right: %d, down left: %d, down right: %d\n", up_left, up_right, down_left, down_right);*/
	    int local_max = max(up_right, max(up_left, max(down_left, down_right)));
	    ans = min(ans, local_max);
	}
    }

    cout << ans << "\n";

    return 0;
}

