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
using vpii = v<pii>;

function<bool(vvi&, vvi&, int, int, pii)> mov_down;
function<bool(vvi&, vvi&, int, int, pii)> mov_up;
function<bool(vvi&, vvi&, int, int, pii)> mov_left;
function<bool(vvi&, vvi&, int, int, pii)> mov_right;

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

vvi base_cw = {
    {9, 2, 3},
    {8, 1, 4},
    {7, 6, 5, 16}
};

vvi base_ccw = {
    {3, 2, 9},
    {4, 1, 8},
    {16, 5, 6, 7}
};

int oob(int i, int j, int n, int m) {
    return i < 0 || j < 0 || i >= n || j >= m;
}

pii convert_to_base_idx(int i, int j, int i_start, int j_start) {
    if (i == i_start && j == j_start) return {1, 1};
    pii diff = {i - i_start, j - j_start};
    return {1 + diff.first, 1 + diff.second};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // fio("<filename_prefix>")
    //
    int n, m, k; cin >> n >> m >> k;
    v<pair<pii, int>> pos;
    const vpii CW_MOVT = {{-1, 0}, {0, 1}, {1, 0}, {1, 0}, {0, -1}, {0, -1}, {-1, 0}, {-1, 0}};
    const vpii CCW_MOVT = {{-1, 0}, {0, -1}, {1, 0}, {1, 0}, {0, 1}, {0, 1}, {-1, 0}, {-1, 0}};
    vvi field(n, vi(m, INT_MAX));

    for (int i_ = 0; i_ < k; i_++) {
	int a, b, c;
	cin >> a >> b >> c;
	a--; b--;
	pos.push_back({{a, b}, c}); //adjusted
    }

    mov_right = [&](vvi& fld, vvi& base, int i, int j, pii base_idx) -> bool {
	if (j + 1 >= m) return false;
	j++;
	base_idx = convert_to_base_idx(i, j, base_idx.first, base_idx.second);
	int x, y;
	tie(x, y) = base_idx;
	if (!oob(i, j, 3, 3) && base[x][y]) fld[i][j] = base[x][y];
	else fld[i][j] = (fld[i][j-1] - fld[i][j-2] + 8) + fld[i][j-1];
	mov_right(fld, base, i, j + 1, base_idx);

	return true;
    };

    mov_left = [&](vvi& fld, vvi& base, int i, int j, pii base_idx) -> bool {
	if (j - 1 < 0) return false;
	j--;
	int x, y;
	tie(x, y) = base_idx;
	if (!oob(i, j, 3, 3) && base[x][y]) fld[i][j] = base[x][y];
	else fld[i][j] = (fld[i][j+1] - fld[i][j+2] + 8) + fld[i][j+1];
	mov_left(fld, base, i, j - 1, base_idx);

	return true;
    };

    mov_up = [&](vvi& fld, vvi& base, int i, int j, pii base_idx) -> bool {
	if (i - 1 < 0) return false;
	i--;
	int x, y;
	tie(x, y) = base_idx;
	if (!oob(i, j, 3, 3) && base[x][y]) fld[i][j] = base[x][y];
	else fld[i][j] = (fld[i+1][j] - fld[i+2][j] + 8) + fld[i+1][j];
	mov_up(fld, base, i - 1, j, base_idx);

	return true;
    };

    mov_down = [&](vvi& fld, vvi& base, int i, int j, pii base_idx) -> bool {
	if (i + 1 >= n) return false;
	i++;
	int x, y;
	tie(x, y) = base_idx;
	if (!oob(i, j, 3, 3) && base[x][y]) fld[i][j] = base[x][y];
	else fld[i][j] = (fld[i-1][j] - fld[i-2][j] + 8) + fld[i-1][j];
	mov_down(fld, base, i + 1, j, base_idx);

	return true;
    };


    for (const auto& p: pos) {
	vvi in_fld(n, vi(m, INT_MAX));
	pii x; int type;
	int i, j;
	tie(x, type) = p;
	tie(i, j) = x;

	auto& base = type == 0 ? base_cw : base_ccw;
	auto& movt = type == 0 ? CW_MOVT : CCW_MOVT;
	in_fld[i][j] = 1;

	auto dfs = [&]() {
	    mov_right(in_fld, base, i, j, {i, j});
	    mov_left(in_fld, base, i, j, {i, j});
	    mov_up(in_fld, base, i, j, {i, j});
	    mov_down(in_fld, base, i, j, {i, j});
	};
	dfs();

	for (int k = 0; k < n; k++) {
	    for (int l = 0; l < m; l++) {
		field[k][l] = min(field[k][l], in_fld[k][l]);
		cout << in_fld[k][l] << " ";
		/*printf("field: %d, in_field: %d\n", field[k][l], in_fld[k][l]);*/
	    }
	    cout << '\n';
	}
	cout << "================\n";
    }

    for (int k = 0; k < n; k++) {
	for (int l = 0; l < m; l++) {
	    cout << field[k][l] << " ";
	}
	cout << '\n';
    }



    return 0;
}


/*
 *
 *
*/
