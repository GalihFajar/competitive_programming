#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vti3 = vector<tuple<int, int, int>>;
using vti4 = vector<tuple<int, int, int, int>>;

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

vti4 aircons;
vti3 cows;
vi curr_subset;
vvi subsets;
int optimal_cost = INT_MAX;

void fill_subset(int k) {
    if (k == aircons.size()) {
	// process
	int total_cost = 0;
	vi current_stall_condition(105, 0);

	for (int aircon_subset: curr_subset) {
	    tuple<int, int, int, int> aircon = aircons[aircon_subset];
	    int air_begin, air_end, down_by_temp, cost;
	    tie(air_begin, air_end, down_by_temp, cost) = aircon;
	    total_cost += cost;

	    for (int i = air_begin; i <= air_end; i++) {
		current_stall_condition[i] += down_by_temp;
	    }
	}

	/*cout << "curr_subset: "; print_v(curr_subset);*/
	/*cout << "curr_condition: "; print_v(current_stall_condition);*/

	for (tuple<int, int, int> cow: cows) {
	    int cow_begin, cow_end, cow_temp;
	    tie(cow_begin, cow_end, cow_temp) = cow;

	    int is_enough = true;
	    for (int i = cow_begin; i <= cow_end; i++) {
		is_enough = is_enough && (cow_temp - current_stall_condition[i] <= 0);
	    }

	    if (!is_enough) return;
	}


	optimal_cost = min(total_cost, optimal_cost);
	return;
    }

    fill_subset(k + 1);
    curr_subset.push_back(k);
    fill_subset(k + 1);
    curr_subset.pop_back();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;

    while (n--) {
	int a, b, c;
	cin >> a >> b >> c;
	cows.push_back({a, b, c});
    }

    while (m--) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	aircons.push_back({a, b, c, d});
    }

    fill_subset(0);
    cout << optimal_cost << endl;


    return 0;
}
