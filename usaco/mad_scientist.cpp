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
    
    freopen("breedflip.in", "r", stdin); 
    freopen("breedflip.out", "w", stdout);

    int n; cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;
    for (int i = 0; i < n; i++) {
	if (s1[i] == s2[i]) continue;

	while (s1[i] != s2[i]) {
	    i++;
	}
	ans++;
    }

    cout << ans << endl;



    return 0;
}

/*
*/
