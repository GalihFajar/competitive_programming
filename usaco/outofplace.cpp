#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("outofplace.in", "r", stdin); 
    freopen("outofplace.out", "w", stdout);

    int n; cin >> n;
    vi input;
    while (n--) {
	int x; cin >> x;
	input.push_back(x);
    }
    int count = 0;
    n = (int) input.size();

    vi sorted = input;
    sort(all(sorted));

    int diff = 0;
    for (int i = 0; i < input.size(); i++) {
	if (sorted[i] != input[i]) diff++;
    }

    cout << diff - 1 << endl;

    return 0;
}

/* 
- Bubble sort swap count maybe?
- Wait it's bascially partially sorted, no need to full sort
- Try to find Bessy and put it in the correct position
- It doesn't direclty work
- Can it has something to do with sorting?
- Not sure.
- *sees hints*
- Damn it got to do with sorting
- Sort and compare
- AC
- Why does it work?
- Basically Bessie displaces cow (like shift the cows), so we could determine
  the how many is it shifted by comparing the different values. Of 
  course this also takes account on same values, so it doesn't get counted twice

*/


// 2 4 7 7 9 3
