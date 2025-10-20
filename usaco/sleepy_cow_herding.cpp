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

const int MAX_POS = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("herding.in", "r", stdin); 
    freopen("herding.out", "w", stdout);

    int x, y, z; cin >> x >> y >> z;
    vi input = {x, y, z};
    sort(all(input));

    int a = input[0], b = input[1], c = input[2];

    if (a == b - 1 && c == b + 1) {
	cout << 0 << endl << 0 << endl;
	return 0;
    }

    int left_space = b - a - 1;
    int right_space = c - b - 1;

    int min_move, max_move;
    if (left_space > 0 && right_space == 0) {
	max_move = left_space;
	if (c == MAX_POS) {
	    min_move = min(max_move, 2);
	} else {
	    min_move = min(max_move, 2);
	}
    } else if (right_space > 0 && left_space == 0) {
	max_move = right_space;
	if (a == 1) {
	    min_move = min(max_move, 2);
	} else {
	    min_move = min(max_move, 2);
	}
    } else {
	min_move = min(2, min(left_space, right_space));
	max_move = max(left_space, right_space);
    }

    cout << min_move << endl << max_move << endl;


    return 0;
}
