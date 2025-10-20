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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("paint.in", "r", stdin); 
    freopen("paint.out", "w", stdout);
    v<bool> vect(103, false);

    int a, b, c, d; cin >> a >> b >> c >> d;

    for (int i = a; i <= b; i++) {
	vect[i] = true;
    }

    for (int i = c; i <= d; i++) {
	vect[i] = true;
    }


    int ans = 0;
    for (int i = 0; i < 102; i++) {
	if (vect[i] == true) {
	    int start = i;
	    while (vect[i] == true) {
		i++;
	    }
	    int end_ = i - 1;
	    ans += (end_ - start);
	}
    }

    cout << ans << endl;


    return 0;
}


/*
 *
 *
*/
