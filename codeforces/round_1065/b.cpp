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
#define fio(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout);
#define psp(x) cout << x << " ";
#define pnl(x) cout << x << "\n";

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

    // fio("<filename_prefix>")
    int tc; cin >> tc;
    while (tc--) {
	int n; cin >> n;
	vi input(n); 
	for (int i = 0; i < n; i++) {
	    int x; cin >> x;

	    if (x == -1) {
		if (i != 0 && i != n - 1) {
		    input[i] = 0;
		} else {
		    input[i] = x;
		}
	    } else {
		input[i] = x;
	    }

	}
	if (input[0] == -1 && input[n - 1] == input[0]) {
	    input[0] = 0; input[n - 1] = 0;
	} else if (input[0] == -1 && input[n - 1] != -1){
	    input[0] = input[n - 1];
	} else if (input[0] != -1 && input[n - 1] == -1) {
	    input[n - 1] = input[0];
	}

	cout << abs(input[n - 1] - input[0]) << endl;
	print_v(input);
    }
    

    return 0;
}


/*
 *
 *
*/
