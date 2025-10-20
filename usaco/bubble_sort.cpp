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

template <typename T>
void print_v(vector<T>& v) {
    for (auto const& elem: v) {
	cout << elem << " ";
    }
    cout << endl;
}

int bub_sort(vi& arr) {
    int n = (int) arr.size();
    int nos = 0;

    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n - 1; j++) {
	    if (arr[j] > arr[j + 1]) {
		swap(arr[j], arr[j + 1]);
		nos++;
	    }
	    print_v(arr);
	}
    }

    return nos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; vi arr;
    cin >> n;
    while (n--) {
	int x; cin >> x;
	arr.push_back(x);
    }

    int nos = bub_sort(arr);


    printf("Array is sorted in %d swaps.\n", nos);
    printf("First Element: %d\n", arr[0]);
    printf("Last Element: %d\n", arr[arr.size() - 1]);

    return 0;
}
