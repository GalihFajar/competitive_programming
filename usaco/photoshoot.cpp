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

void print_v_pair(vector<pair<int, pii>>& v) {
    for (auto const& elem: v) {
	cout << elem.first << " ";
	printf("-> {%d, %d}\n", elem.second.first, elem.second.second);
    }
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    /*freopen("<FILENAME>.in", "r", stdin); */
    /*freopen("<FILENAME>.out", "w", stdout);*/

    int n; cin >> n;
    string s; cin >> s;
    int count = 0;
    bool swapped = false;

    for (int i = s.size() - 1; i > 0; i-= 2) {
	char even = s[i];
	char odd = s[i - 1];

	if (swapped) {
	    swap(even, odd);
	}

	if (odd == 'G' && even != 'G') {
	    count++;
	    swapped = !swapped;
	}
    }

    cout << count << endl;
    

    return 0;
}


/*
- Current approach makes decision at index k influenced by index below it
- Example is HGGH, on last pos it should be swapped, but since odd == even it's not'
- Looking at hints
- So the idea is to just swap, from right to left, whether G is already in the good place or not
- That's very greedy and it works
 */
