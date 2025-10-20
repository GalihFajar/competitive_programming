#include <iostream>
#include <map>
#include <string>
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

template <typename T>
void print_v_newline(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << '\n';
    }
}

string to_string(vi& v) {
    string s = "";
    for (auto const& x: v) {
	s += to_string(x);
    }

    return s;
}

bool compare_two_v(vi& v1, vi& v2) {
    if (v1.size() != v2.size()) return false;

    for (int i = 0; i < v1.size(); i++) {
	if (v1[i] != v2[i]) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("swap.in", "r", stdin); 
    freopen("swap.out", "w", stdout);
    int n; int k; cin >> n >> k;
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;

    vi v;
    for (int i = 1; i <= n; i++) {
	v.push_back(i);
    }

    vvi ans;
    unordered_map<string, vi> um;
    vi def = v;

    ans.push_back(v);

    for (int i = 1;; i++) {
	reverse(v.begin() + (a1 - 1), v.begin() + a2);
	reverse(v.begin() + (b1 - 1), v.begin() + b2);
	if (compare_two_v(v, def)) {
	    break;
	}

	ans.push_back(v);
    }

    print_v_newline(ans[k % (int) ans.size()]);
    return 0;

	/*   if (k <= ans.size()) {*/
	/*print_v_newline(ans[k-1]);*/
	/*return 0;*/
	/*   } else {*/
	/*int idx = k% (int) ans.size();*/
	/*idx = idx == 0 ? 0 : idx - 1;*/
	/*print_v_newline(ans[idx]);*/
	/*return 0;*/
	/*   }*/
	/**/

    return -1;
}


/*
 * It's impossible to swap in O(1) time, there must be some tricks to it
 * Let's see hint
 * Turns out after x swap, the set comes back, so there must be a cycle
 * We could utilize mod
 * At what point the set comes back to beginning
 * There are distinct patterns for each problem, so we need to simulate it
 * Get the max number such that swap is making it back to beginning
 * AC
 *
*/
