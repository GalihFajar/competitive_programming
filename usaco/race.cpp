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

int calc_sum(int x) {
    return (x * (x + 1)) / 2;
}

int solve(int dist, int speed_limit) {

    int acc_dist = 0, time = 0, decc_dist = 0;
    for (int curr_speed = 1;; curr_speed++) {
	acc_dist += curr_speed;
	time++;

	if (acc_dist + decc_dist >= dist) return time;

	if (curr_speed >= speed_limit) {
	    decc_dist += curr_speed;
	    time++;

	    if (acc_dist + decc_dist >= dist) return time;
	}
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("race.in", "r", stdin); 
    freopen("race.out", "w", stdout);

    int n, k; cin >> n >> k;
    while (k--) {
	int x; cin >> x;
	cout << solve(n, x) << endl;
    }

    return 0;
}


/*
- Since Bessie wants to finish at speed X, let's try to work backwards
- Ok  after some attempts, they don't work
- Try seeking help from Gemini & Claude
- They don't make sense and they're not sure if braking in time is possible
- Seeking solution from the usaco (official) solution
- Interesting, turns out we could do brute force since the iteration scales exponentially
    - Solution is always t(t + 2)/2 >= K where K is distance covered (arithmetic series)
- It could be simulated, up until the speed doesn't reach max, we're good, as soon as it reaches max, we need to consider brake
- It seems skeptical whether it could brake in time or not, but it is, since we're iterating through all the possibilities and if it turns out the solution
 is in the next iteration, the last element (max_speed) is in the range just about it finishes
- Another way to prove this, more of a assumption is that since we already iterated through all the possibilities, there should be a solution.

- Harder thing to prove is whether we should cruise or not, but since this is greedy, we aim for the best, always!
*/ 
