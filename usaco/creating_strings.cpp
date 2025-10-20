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
using vs = vector<string>;
using vb = vector<bool>;

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

string input;
vs output;
vb visited;

vi total_list = vi(26, 0);



void permute(string curr) {
    if (curr.size() == input.size()) {
	output.push_back(curr);
	return;
    }

    for (int i = 0; i < 26; i++) {
	if (!total_list[i]) continue;
	total_list[i]--;
	curr.push_back('a' + i);
	permute(curr);
	curr.pop_back();
	total_list[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> input;

    string curr = "";

    for (auto const& x: input) {
	total_list[x - 'a']++;
    }

    permute(curr);

    cout << output.size() << "\n";
    for (auto const& x: output) {
	cout << x << "\n";
    }


    return 0;
}
