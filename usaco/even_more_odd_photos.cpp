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

int calc(int odds, int evens) {
    if (odds < 0 || evens < 0) return -1;
    if (evens == odds || evens - 1 == odds) {
	return evens + odds;
    } else if (evens - odds > 1){
	return odds + odds + 1;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int odds = 0, evens = 0;
    while (n--) {
	int x; cin >> x;
	if (x & 1) { // odd
	    odds++;
	} else {
	    evens++;
	}
    }

    while (odds > evens) {
	odds -= 2;
	evens++;
    }

    if (evens > odds + 1) { // cap the evens
	evens = odds + 1;
    }

    cout << odds + evens << endl;

    return 0;
}


/*
 * Looks like we could count the number of evens and odds
 * The allowed number of even and odss are:
    * even == odd
    * even + 1 == odd (optimal)
 * It looks like from odd, we could get odds and evens
     * if K is odd then:
	 * K odds
	 * K/2 evens, and K % 2 odds
	 * K - 2 odds, and 1 even
 * Note:
     * odd + odd = even
     * even + odd = odd
     * even + even  = even
 * Lol doesn't work, lets see hints
 * Turns out that the core idea is the same, if we have too many oods, we can turn them into evens
 * Then if evens is too much, since we can't turn evens to odds, we cap the evens'
*/
