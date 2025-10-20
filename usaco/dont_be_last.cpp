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
using vs = v<string>;
template <typename K, typename T> using um = unordered_map<K, T>;

#define all(x) begin(x), end(x)

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

const vs COWS = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("notlast.in", "r", stdin); 
    freopen("notlast.out", "w", stdout);

    um<string, int> map;
    vi yield(7, 0);

    int n; cin >> n;
    while (n--) {
	string s; int in; cin >> s >> in;
	map[s] += in;
    }

    int idx = 0;
    for (auto const& [k, v]: map) {
	/*cout << k << " " << v << endl;*/
	yield[idx++] = v;
    }

    sort(all(yield));

    int second = [&]() -> int {
	for (auto x: yield) {
	    if (x > yield[0]) {
		return x;
	    }
	}

	return -1;
    }();

    if (second == 0) {
	cout << "Tie\n"; return 0;
    }

    vs ans;
    for (auto const& [k, v]: map) {
	if (v == second) {
	    ans.push_back(k);
	}
    }

    if (ans.size() != 1) {
	cout << "Tie" << endl;
	return 0;
    }

    cout << ans[0] << endl;


    return 0;
}
