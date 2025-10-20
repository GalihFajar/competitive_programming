#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <queue> 
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vs = v<string>;

#define all(x) begin(x), end(x)

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

void flip(vs& inp, int row_max, int col_max) {
    for (int i = 0; i <= row_max; i++) {
	for (int j = 0; j <= col_max; j++) {
	    if (inp[i][j] == '1') inp[i][j] = '0';
	    else inp[i][j] = '1';
	}
    }
}

v<v<bool>> visited = v<v<bool>>(100, v<bool>(100));

void process(vs& inp, int& cnt, queue<pair<int, int>>& q) {
    pair<int, int> current = q.front();
    int row = current.first, col = current.second;
    q.pop();

    pair<int, int> nxt_1 = {row - 1, col};
    pair<int, int> nxt_2 = {row, col - 1};

    if (inp[row][col] == '1') {
	flip(inp, row, col);
	cnt++;
    }

    if (nxt_1.first >= 0 && nxt_1.second >= 0) {
	if (!visited[nxt_1.first][nxt_1.second]) {
	    q.push(nxt_1);
	}
    }

    if (nxt_2.first >= 0 && nxt_2.second >= 0) {
	if (!visited[nxt_2.first][nxt_2.second]) {
	    q.push(nxt_2);
	}
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("cowtip.in", "r", stdin); 
    freopen("cowtip.out", "w", stdout);

    int n; cin >> n;
    vs inp;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++){
	string s; cin >> s;
	inp.push_back(s);
    }

    q.push({n - 1, n - 1});
    int count = 0;

    while (!q.empty()) {
	process(inp, count, q);
    }
    
    cout << count << endl;


    return 0;
}


/*
 *
 * Seems like the priority is to tip the rightmost (right side) of the square
 * Greedly, we just need to change the right bottom corner no matter what, and put that into count
 * It works lol
 *
*/
