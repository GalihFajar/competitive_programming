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

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << v << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
	int n; cin >> n;
	int total = 0;
	vi input;
	while (n--) {
	/*cout << "done2\n";*/
	   int x; cin >> x;
	    input.push_back(x);
	    total += x;
	}
	vi divisors;
	// adsf

	if (total == 0) {
	    cout << 0 << endl;
	    continue;
	}

	// get divisors
	for (int i = 1; i <= sqrt(total); i++) {
	    if (total % i == 0) {
		divisors.push_back(i);
		divisors.push_back(total / i);
	    }
	}

	sort(divisors.begin(), divisors.end());

	bool found = false;
	for (int div: divisors) {
	    int current_total = 0;
	    bool dividable = true;
	    int total_addition = 0;
	    bool first_addition = true;
	    for (int i = 0; i < input.size(); i++) {
		if (!first_addition) total_addition++;
		first_addition = false;
		current_total += input[i];
		if (current_total == div) {
		    current_total = 0;
		    first_addition = true;
		} else if (current_total > div){
		    dividable = false;
		    break;
		}
	    }

	    if (dividable) {
		cout << total_addition << endl; 
		found = true;
		break;
	    }
	}

	if (!found) cout << input.size() - 1 << endl;
    }

    return 0;
}
