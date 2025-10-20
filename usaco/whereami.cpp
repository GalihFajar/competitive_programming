#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include<set>
#include<map>
using namespace std;

template <typename T> using v = vector<T>;
template <typename K, typename T> using um = unordered_map<K, T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

using vset = v<set<char>>;

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
    
    freopen("whereami.in", "r", stdin); 
    freopen("whereami.out", "w", stdout);
    set<char> s;
    vset vs;

    int n; cin >> n;

    string input;
    int ans = INT_MAX;
    um<string, int> map;
    um<int, int> count_map;

    cin >> input;

    for (int i = 0; i < input.size(); i++) {
	string s = "";
	for (int j = i; j < input.size(); j++) {
	    s += input[j];
	    map[s]++;
	    /*cout << "s: " << s << endl;*/
	}
    }

    for (auto const& [key, val]: map) {
	/*cout << "key: " << key << " val: " << val << endl;*/
	count_map[key.size()] = max(val, count_map.count(key.size()) ? count_map[key.size()] : -1);
	/*cout << key.size() << " " << count_map[key.size()] << endl;*/
    }

    for (auto const& [key, val]: count_map) {
	/*printf("{k, v}: {%d, %d}\n", key, val);*/
	if (val == 1) {
	    ans = min(ans, key);
	}
    }

    cout << ans << endl;

    return 0;
}
