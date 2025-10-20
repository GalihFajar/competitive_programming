
#include <iostream>
#include <queue>
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
#define foridx(x) for (int i = 0; i < x.size(); i++)
#define foridxrev(x) for (int i = x.size() - 1; i >= 0; i--)

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

void traverse(int start, v<bool>& visited, vvi& outdeg) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
	int x = q.front(); q.pop();
	if (visited[x]) continue;
	visited[x] = true;

	foridx(outdeg[x]) {
	    q.push(outdeg[x][i]);
	}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("hoofball.in", "r", stdin); 
    freopen("hoofball.out", "w", stdout);
    int n; cin >> n;
    vi input;
    vvi outdeg(1001);
    v<bool> included = v<bool>(1001, false);

    for (int i = 0; i < n; i++) {
	int x; cin >> x;
	input.push_back(x);
	included[x] = true;
    }

    sort(all(input));

    foridx(input) {
	int curr_dist = input[i];
	int prev_dist = i == 0 ? -1 : input[i - 1];
	int next_dist = i == input.size() - 1 ? -1 : input[i + 1];

	if (i == 0) {
	    outdeg[curr_dist].push_back(next_dist);
	    continue;
	}

	if (i == input.size() - 1) {
	    outdeg[curr_dist].push_back(prev_dist);
	    continue;
	}

	if (abs(curr_dist - prev_dist) <= abs(curr_dist - next_dist)) {
	    outdeg[curr_dist].push_back(prev_dist);
	} else {
	    outdeg[curr_dist].push_back(next_dist);
	}     
    }

    vvi indeg(1001);
    foridx(outdeg) {
	if (outdeg[i].empty()) continue;
	for (auto const& x: outdeg[i]) {
	    indeg[x].push_back(i);
	}
    }

    vi candidate;
    int cnt = 0;
    foridx(input) {
	if (indeg[input[i]].empty()) {
	    /*cnt++;*/
	    candidate.push_back(input[i]);
	};
    }

    v<bool> visited = v<bool>(1001, false);
    foridx(candidate) {
	int c = candidate[i];
	if (visited[c]) continue;
	traverse(c, visited, outdeg);
	cnt++;
    }

    foridxrev(input) {
	if (visited[input[i]]) continue;
	cnt++;
	traverse(input[i], visited, outdeg);
    }

    cout << cnt << endl;


    return 0;
}


/*
 * For every point, we could determine for that point what is the nearest point to it
 * If it's tie to the nearest, add anyways
 * Correction, on the problem statement it's implicitly said that it should be connected to the left only
 * Ok now just count the number of connected graphs, with the node with only out degree being the priority
 * It works 
*/
