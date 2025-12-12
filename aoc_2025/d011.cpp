#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vs = v<string>;
using ll = long long;
using vvll = v<v<ll>>;

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

vvi adj_list;
unordered_map<string, int> map;
unordered_map<string, v<string>> map_string;
unordered_map<string, int> dp;
unordered_map<string, vvll> dp_2;

int node_num = 0;
int resolve_map(string& s) {
    if (map.count(s)) return map[s];

    map[s] = node_num++;
    return map[s];
}

int dfs(string current) {
    if (current == "out") return 1;
    if (dp[current]) return dp[current];

    vs neighbors = map_string[current];
    int n = neighbors.size();

    int path = 0;
    for (int i = 0; i < n; i++) {
	path += dfs(neighbors[i]);
    }

    dp[current] = path;

    return path;
}

ll dfs_fft(string current, bool fft_visited, bool dac_visited) {
    if (current == "out" && fft_visited && dac_visited) return 1;
    if (current == "out") return 0;

    if (current == "fft") fft_visited = true;
    if (current == "dac") dac_visited = true;

    if (dp_2.count(current)) {
	ll ans = dp_2[current][fft_visited][dac_visited];
	if (ans != -1) return ans;
    }

    dp_2[current] = vvll(2, v<ll>(2, -1));

    vs neighbors = map_string[current];
    int n = neighbors.size();

    ll path = 0;
    for (int i = 0; i < n; i++) {
	ll next = dfs_fft(neighbors[i], fft_visited, dac_visited);
	path += next;
    }

    dp_2[current][fft_visited][dac_visited] = path;

    return path;
}


void print_map() {
    for (auto const& x: map_string) {
	cout << x.first << ": "; 
	for (auto const& s: x.second) {
	    cout << s << " ";
	}
	cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    //
    string line;
    while (getline(cin, line)) {
	string temp = "";
	v<string> temp_v;
	for (auto c: line) {
	    if (c != ' ' && c != ':') {
		temp += c;
	    } else {
		if (!temp.empty()) {
		    temp_v.push_back(temp);
		}
		temp.clear();
	    }
	}

	if (!temp.empty()) temp_v.push_back(temp);

	for (int i = 1; i < temp_v.size(); i++) {
	    map_string[temp_v[0]].push_back(temp_v[i]);
	}
    }

    cout << "#1: " << dfs("you") << endl;
    cout << "#2: " << dfs_fft("svr", false, false) << endl;


    return 0;
}


/*
 *
 *
*/
