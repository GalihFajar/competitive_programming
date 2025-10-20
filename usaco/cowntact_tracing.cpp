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
	cout << elem << " ";
    }
    cout << endl;
}

bool check_same(vi& a, vi& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
	if (a[i] != b[i]) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("tracing.in", "r", stdin); 
    freopen("tracing.out", "w", stdout);

    int N, T; cin >> N >> T;
    string s; cin >> s;
    vi input_list = [&]() -> vi {
	vi out;
	for (auto const& c: s) {
	    out.push_back((int) c - '0');
	}

	return out;
    }();

    vector<tuple<int, int, int>> ts;

    while (T--) {
	int a, b, c;
	cin >> a >> b >> c;
	ts.push_back({a, b, c});
    }

    sort(ts.begin(), ts.end(), [](tuple<int, int, int> tup1, tuple<int, int, int> tup2) -> bool {
	    int a, b, c, d, e, f;
	    tie(a, b, c) = tup1;
	    tie(d, e, f) = tup2;

	    return a < d;
    });

    int zero_patients = 0, min_shake = INT_MAX, max_shake = INT_MIN;
    vi healthy_field(N, 0);


    vi zp(N, 0);

    for (int k = 0; k < ts.size() + 3; k++) {
	/*cout << "k: " << k << endl;*/
	for (int i = 0; i < input_list.size(); i++) {
	    /*cout << "\ti: " << i << endl;*/
	    if (input_list[i] != 1) continue;
	    vi field(N, 0);
	    /*vi each_infected_cow_shake_total(N, 0);*/
	    field[i] = 1;
	    vi allowed(N, -1);
	    allowed[i] = k;
	    
	    for (auto const& t: ts) {
		int _t, a, b;
		tie(_t, a, b) = t;
		a--; b--;
		/*printf("{a, b}: {%d, %d}\n", a, b);*/

		if (field[a] == 1 && field[b] == 0) {
		    if (allowed[a]) {
			/*cout << "mashook 1\n";*/
			allowed[a]--;
			/*if (allowed[b] == -1) allowed[b] = k;*/
			allowed[b] = k;
			field[b] = 1;
		    }
		} else if (field[b] == 1 && field[a] == 0) {
		    if (allowed[b]) {
			/*cout << "mashook 2\n";*/
			allowed[b]--;
			/*if (allowed[a] == -1) allowed[a] = k;*/
			allowed[a] = k;
			field[a] = 1;
		    }
		} else if (field[a] == 1 && field[b] == 1) {
		    if (allowed[a]) allowed[a]--; if (allowed[b]) allowed[b]--;
		}
		/*cout << "\tinput_list: "; print_v(input_list);*/
	    }
	    /*cout << "k: "  << k << " starting: " << i + 1 << " field: "; print_v(field);*/

	    bool is_same = check_same(field, input_list);
	    
	    if (is_same) {
		zp[i]++;
		min_shake = min(k, min_shake);
		max_shake = max(k, max_shake);
	    }
	}
	/*cout << "\n\n\n";*/
    }

    zero_patients = [&]() -> int {
	int a = 0;
	for (auto const& x: zp) {
	    if (x > 0) a++;
	}

	return a;
    }();

    cout << zero_patients << " " << min_shake << " ";

    if (max_shake > ts.size()) {
	cout << "Infinity\n";
    } else {
	cout << max_shake << "\n";
    }


    return 0;
}
