#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vb = v<bool>;


vs COWS = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vb visited = vb(10);
v<vi> condition(10);
vvi pot_answers;

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

int resolve_cow_number(string& s) {
    for (int i = 0; i < COWS.size(); i++) {
	if (COWS[i] == s) return i;
    }

    return -1;
}

int x = 0;
void permute(vi& current) {
    if (current.size() >= COWS.size()) {
	/*print_v(current);*/
	/*cout << "current: "; print_v(current);*/
	for (int i = 0; i < (int) current.size(); i++) {
	    int curr_cow_num = current[i];
	    if (condition[curr_cow_num].empty()) continue;
	    int curr_cow_num_left = i == 0 ? -1 : current[i - 1];
	    int curr_cow_num_right = i == current.size() - 1 ? -1 : current[i + 1];


	    /*printf("%d <- %d -> %d\n", curr_cow_num_left, curr_cow_num, curr_cow_num_right);*/


	    int fulfilled = true;
	    for (auto const& neigh: condition[curr_cow_num]) {
		fulfilled = fulfilled && (curr_cow_num_left == neigh || curr_cow_num_right == neigh);
	    }

	    if (!fulfilled) return;
	}

	pot_answers.push_back(current);
	return;
    }

    for (int i = 0; i < COWS.size(); i++) {
	if (visited[i]) continue;
	current.push_back(i);
	visited[i] = true;
	permute(current);
	visited[i] = false;
	current.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("lineup.in", "r", stdin); 
    freopen("lineup.out", "w", stdout);

    sort(COWS.begin(), COWS.end());
    /*cout << "cows: "; print_v(COWS);*/

    int n; cin >> n;
    while (n--) {
	string cow1, b, c, d, e, cow2;
	cin >> cow1 >> b >> c >> d >> e >> cow2;
	int cw1 = resolve_cow_number(cow1), cw2 = resolve_cow_number(cow2);

	condition[cw1].push_back(cw2);
	condition[cw2].push_back(cw1);
    }



	/*   for (int i = 0; i < condition.size(); i++) {*/
	/*if (condition[i].empty()) continue;*/
	/*sort(condition[i].begin(), condition[i].end());*/
	/*cout << i << ": ";*/
	/*print_v(condition[i]);*/
	/*   }*/
	/**/
    vi curr;
    permute(curr);

    for (auto const& x: pot_answers[0]) {
	cout << COWS[x] << endl;
    }
	/**/
	/*   print_v(pot_answers[0]);*/
	/*   for (int i = 0; i < (int) pot_answers[0].size(); i++) {*/
	/*if (condition[pot_answers[0][i]].empty()) continue;*/
	/*int curr_cow_num = pot_answers[0][i];*/
	/*int curr_cow_num_left = i == 0 ? -1 : pot_answers[0][i - 1];*/
	/*int curr_cow_num_right = i == pot_answers[0].size() - 1 ? -1 : pot_answers[0][i + 1];*/
	/**/
	/*printf("%d <- %d -> %d\n", curr_cow_num_left, curr_cow_num, curr_cow_num_right);*/
	/**/
	/**/
	/*int fulfilled = true;*/
	/*for (auto const& neigh: condition[curr_cow_num]) {*/
	/*    fulfilled = fulfilled && (curr_cow_num_left == neigh || curr_cow_num_right == neigh);*/
	/*}*/
	/**/
	/*if (!fulfilled) cout << "not fulfilled" << endl;;*/
	/*   }*/



    return 0;
}
