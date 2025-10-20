#include <iostream>
#include <iterator>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    n *= 2;
    vi input;
    vi singles;

    while (n--) {
	int x; cin >> x;
	input.push_back(x);
    }

    sort(all(input));
    vi used = vi(input.size(), 0);
    vi sorted_input = vi(input.size() - 2, 0);

    int ans = INT_MAX;
    for (int i = 0; i < input.size(); i++) {
	for (int j = i + 1; j < input.size(); j++) {
	    int idx = 0;
	    int current = -1;
	    int total = 0;
	    for (int k = 0; k < input.size(); k++) {
		if (k == i || k == j) continue;
		sorted_input[idx++] = input[k];
		if (current == -1) {
		    current = input[k];
		} else {
		    total += abs(current - input[k]);
		    current = -1;
		}
	    }
	    ans = min(ans, total);
	}
    }

    cout << ans << endl;

    return 0;
}
