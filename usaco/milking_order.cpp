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

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

bool is_valid(vi& field, vi& order) {
    int order_iter = 0;
    for (int i = 0; i < field.size() && order_iter < order.size(); i++) {
	if (field[i] == order[order_iter]) {
	    order_iter++;
	}
    }

    if (order_iter >= order.size()) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("milkorder.in", "r", stdin); 
    freopen("milkorder.out", "w", stdout);
    vi order;


    int n, m, k;
    cin >> n >> m >> k;

    int m_temp = m;
    vi field = vi(n + 1, 0);
    vi pos = vi(n + 1);
    v<bool> visited = v<bool>(n + 1, false);

    while (m--) {
	int x; cin >> x;
	order.push_back(x);
    }

    while (k--) {
	int x,y; cin >> x >> y;
	field[y-1] = x;
	visited[x] = true;
	pos[x] = y-1;

	if (x == 1) {
	    cout << y << endl;
	    return 0;
	}
    }
	/**/
	/*   if (m_temp == 1) {*/
	/*int iter = 0;*/
	/*while (field[iter]) {*/
	/*    iter++;*/
	/*}*/
	/*field[iter] = order[0];*/
	/*visited[order[0]] = true;*/
	/*   }*/


    v<bool> visited_temp = visited;
    vi temp_field = field;
    for (int i = 0; i < n; i++) {
	// refine the checking process
	if (field[i]) continue;
	field[i] = 1;
	visited[1] = true;
	pos[1] = i;
	
	int last_pos = 0;
	bool valid = true;
	for (int j = 0; j < order.size(); j++) {
	    if (visited[order[j]]) {
		if (last_pos > pos[order[j]]) {
		    valid = false;
		    break;
		} else {
		    last_pos = pos[order[j]];
		}
	    } else {
		bool placed = false;
		for (int k = last_pos; k < field.size(); k++) {
		    if (field[k]) continue;
		    field[k] = order[j];
		    last_pos = k;
		    placed = true;
		    break;
		}

		if (!placed) {
		    valid = false;
		    break;
		}
	    }
	}

	if (valid) {
	    cout << i + 1 << endl;
	    return 0;
	}

	field = temp_field;
	visited = visited_temp;
    }

    cout << 0 << endl;


    return -1;
}
