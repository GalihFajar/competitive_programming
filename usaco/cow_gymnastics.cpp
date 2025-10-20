#include <iostream>
#include <vector>
using namespace std;

template <typename T> using v = vector<T>;
template <typename T> using vv = vector<vector<T>>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
	int n, k;
	cin >> k >> n;
	vvi count(n + 1, vi(n + 1, 0));
	vvi inputs;
	int k_ = k;

	while (k_--) {
		int n_ = n;
		vi input;
		while (n_--) {
			int in; cin >> in;
			input.push_back(in);
		}
		inputs.push_back(input);
	}


	for (auto const& input: inputs) {
		for (int i = 0; i < input.size(); i++) {
			for (int j = i + 1; j < input.size(); j++) {
				count[input[i]][input[j]]++;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < count.size(); i++) {
		for (int j = 0; j < count.size(); j++) {
			if (count[i][j] == k) {
				/*cout << "i, j: " << i << "," << j << endl;*/
				ans++;
			}
		}
	}

	/**/
	/*for (auto const& x: count) {*/
	/*	for (auto const& elem: x) {*/
	/*		ans += elem == k;*/
	/*	}*/
	/*}*/
	/**/
	cout << ans << "\n";
	return 0;
}
