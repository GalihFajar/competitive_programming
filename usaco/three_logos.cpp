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
using vb = v<bool>;
using vpii = v<pii>;
using vs = v<string>;

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

vb visited = vb(6, false);
vpii points;
v<vpii> type_1;
v<vpii> type_2;
vs type_1_chars;
vs type_2_chars;

char resolve_letter_default(int x) {
    if (x == 0) return 'A';
    if (x == 1) return 'B';
    return 'C';
}

char resolve_letter_on_permute(int x) {
    if (x == 0 || x == 1) return 'A';
    if (x == 2 || x == 3) return 'B';
    return 'C';
}


void permute(vi& current) {

    if (current.size() == 3) {
	// process
	pair<int, int> p1 = points[current[0]], p2 = points[current[1]], p3 = points[current[2]];
	int x1, y1, x2, y2, x3, y3;
	tie(x1, y1) = p1;
	tie(x2, y2) = p2;
	tie(x3, y3) = p3;

	string s;
	s += resolve_letter_on_permute(current[0]);
	s += resolve_letter_on_permute(current[1]);
	s += resolve_letter_on_permute(current[2]);

	if (y1 == y2 && y2 == y3) {
	    if (y1 == (x1 + x2 + x3)) {
		type_1.push_back({p1, p2, p3});
		type_1_chars.push_back(s);
		return;
	    }
	}

	if ((y1 == (y2 + y3)) && (x2 == x3)) {
	    if (y1 == (x1 + x2)) {
		type_2.push_back({p1, p2, p3});
		type_2_chars.push_back(s);
		return;
	    }
	}

	return;
    }


    for (int i = 0; i < 6; i++) {
	if (visited[i]) continue;
	visited[i] = true;
	visited[(i & 1 ? i - 1 : i + 1)] = true;
	current.push_back(i);
	permute(current);
	current.pop_back();
	visited[i] = false;
	visited[(i & 1 ? i - 1 : i + 1)] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    points.push_back({a, b});
    points.push_back({b, a});

    points.push_back({c, d});
    points.push_back({d, c});

    points.push_back({e, f});
    points.push_back({f, e});

    vi curr;
    permute(curr);

   if (!type_1.empty()) {
	int start = 0;
	vpii chosen = type_1[0];
	int a, b, c, d, e, f;
	tie(a, b) = chosen[0];
	tie(c, d) = chosen[1];
	tie(e, f) = chosen[2];

	cout << chosen[0].first + chosen[1].first + chosen[2].first << '\n';
	for (int i = 0; i < chosen.size(); i++) {
	    for (int k = 0; k < chosen[i].first; k++) {
		string s = string(chosen[i].second, type_1_chars[0][i]);
		cout << s << endl;
	    }
	}
	return 0;

    } else if (!type_2.empty()) {
	vpii chosen = type_2[0];
	string chosen_chars = type_2_chars[0];
	vs out = vs(chosen[0].second, string(chosen[0].first + chosen[1].first, ' '));


	for (int i = 0; i < chosen[0].second; i++) {
	    for (int j = 0; j < chosen[0].first; j++) {
		out[i][j] = chosen_chars[0];
	    }
	}

	int i_ = 0, start_j = chosen[0].first;

	for (i_; i_ < chosen[1].second; i_++) {
	    for (int j = start_j; j < chosen[1].first + start_j; j++) {
		out[i_][j] = chosen_chars[1];
	    }
	}

	for (i_; i_ < chosen[2].second + chosen[1].second; i_++) {
	    for (int j = start_j; j < chosen[2].first + start_j; j++) {
		out[i_][j] = chosen_chars[2];
	    }
	}

	cout << chosen[0].second << '\n';
	for (auto x: out) {
	    cout << x << '\n';
	}
	return 0;
    }

    cout << "-1" << endl;


    return 0;
}
