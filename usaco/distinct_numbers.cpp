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

    int n;
    cin >> n;
    vi input;

    while (n--) {
	int x; cin >> x;
	input.push_back(x);
    }

    sort(all(input));
    auto new_end = unique(all(input));
    input.erase(new_end, input.end());

    cout << input.size() << '\n';

    return 0;
}
