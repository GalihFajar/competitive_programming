#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

template <typename T> using v = vector<T>;
template <typename T> using us = unordered_set<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vs = v<string>;
using vvs = v<vs>;
using vpis = v<pair<int, vs>>;

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
    
    freopen("evolution.in", "r", stdin); 
    freopen("evolution.out", "w", stdout);

    int n; cin >> n;
    v<us<string>> cows;
    us<string> all_feats_set;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
	int k; cin >> k;
	us<string> t;
	for (int j = 0; j < k; j++) {
	    string x; cin >> x;
	    t.insert(x);
	}
	all_feats_set.insert(t.begin(), t.end());
	cows.push_back(t);
    }

    v<string> all_feats(all(all_feats_set));

    // check on all feats if there is a disjoint set
    for (int a = 0; a < all_feats.size(); a++) {
	for (int b = a + 1; b < all_feats.size(); b++) {
	    bool only_a = false, only_b = false, both = false;
	    for (auto const& cow_feat: cows) {
		bool has_a = cow_feat.count(all_feats[a]);
		bool has_b = cow_feat.count(all_feats[b]);

		if (has_a && !has_b) {
		    only_a = true;
		} else if (!has_a && has_b) {
		    only_b = true;
		} else if (has_a && has_b) {
		    both = true;
		}
	    }

	    if (only_a && only_b && both) {
		cout << "no\n";
		return 0;
	    }
	}
    }


    cout << "yes\n";
    return 0;
}


/*
 * A tree construction problem.
 * Question is, should we try to construct the tree, or we could see any characteristic whether it's possible or not
 * Let's try with simulation first
 * Ok it doesnt work
 * Let's see hint
 * Ok so the idea is to not have a intersecting feature, that is a there is a cow that has feat a only, feat b only, and has both
 * Let's write it
 * AC
*/
