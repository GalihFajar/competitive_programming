#include <iostream>
#include <vector>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vs = v<string>;

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

int total_split = 0;

void dfs(vs& input, int i, int j) {
    if (i < 0 || j < 0 || i >= input.size() || j >= input[i].size()) return;

    if (input[i][j] == '.') {
	input[i][j] = '|';
	dfs(input, i + 1, j);
    } else if (input[i][j] == '^') {
	total_split++;
	dfs(input, i, j + 1);
	dfs(input, i, j - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    vs input;
    string s;
    while (cin >> s) {
	input.push_back(s);
    }

    pii start;
    for (int i = 0; i < input[0].size(); i++) {
	if (input[0][i] == 'S') start = {0, i};
    }

    dfs(input, start.first + 1, start.second);
    for (auto const& s: input) {
	cout << s << endl;
    }

    cout << "total split: " << total_split << endl;



    return 0;
}


/*
 *
 *
*/
