#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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
    
    freopen("factory.in", "r", stdin); 
    freopen("factory.out", "w", stdout);

    int n; 
    cin >> n;
    vvi outdeg = vvi(n + 1);
    vvi indeg = vvi(n + 1);
    vi processed = vi(n + 1);

    for (int i = 0; i < n - 1; i++) {
	int a, b; cin >> a >> b;
	outdeg[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
	for (int j = 0; j < outdeg[i].size(); j++) {
	    indeg[outdeg[i][j]].push_back(i);
	}
    }


    for (int i = 1; i <= n; i++) {
	/*cout << i << ": \n";*/
	/*cout << '\t' << "indeg: "; print_v(indeg[i]);*/
	/*cout << '\t' << "outdeg: "; print_v(outdeg[i]);*/
	if (outdeg[i].size() == 0 && indeg[i].size() != 0) {
	    queue<int> q;
	    int cnt = 0;
	    int candidate = i;
	    for (int i = 0; i < indeg[candidate].size(); i++) {
		q.push(indeg[candidate][i]);
	    }

	    while (!q.empty()) {
		int ind = q.front();
		q.pop();
		if (processed[ind]) continue;
		processed[ind] = true;
		cnt++;
		for (auto const& x: indeg[ind]) {
		    q.push(x);
		}
	    }

	    if (cnt == n - 1) {
		cout << candidate << endl;
		return 0;
	    }
	}
    }

    cout << -1 << endl;

    return 0;
}


/*
 * Probably counting indeg would work
 * It doesn't work lol
 * It turns out work, but the algo should be more careful
 * We should also check the preceding node as well, for example A -> B -> C -> D,
   on D, we should check up until A
 * Now it works
*/
