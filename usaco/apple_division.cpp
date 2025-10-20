#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpvi = vector<pair<vi, int>>;

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

vi input;
vvi subsets;
vvi asdf;
vi subset;
vll subset_total;
long long total;

void gen_subset(int k) {
    if (k == input.size()) {
	subsets.push_back(subset);
	subset_total.push_back(total);
    } else {
	gen_subset(k + 1);
	subset.push_back(k);
	total += input[k];
	gen_subset(k + 1);
	subset.pop_back();
	total -= input[k];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; 
    cin >> n;
    
    while (n--) {
	int x;
	cin >> x;
	input.push_back(x);
    }

    long long total_all = 0;

    for (int& x: input) {
	total_all += x;
    }

    gen_subset(0);
    long long ans = LLONG_MAX;

    for (int i = 0; i < subsets.size(); i++) {
	/*if (subsets[i].size() == input.size()) continue;*/
	/*if (subset_total[i] == 0) continue;*/

	long long tot = [&]() -> long long {
	    long long tot = 0;

	    for (auto x: subsets[i]) {
		tot = tot + input[x];
	    }

	    return tot;
	}();


	/*ans = min(ans, abs(subset_total[i] - (total_all - subset_total[i])));*/
	ans = min(ans, abs(tot - (total_all - tot)));
    }

    cout << ans << "\n";



    return 0;
}


