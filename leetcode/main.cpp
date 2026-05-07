#include <iostream>
#include <vector>
#include "80.cpp"
using namespace std;

template <typename T> using v = vector<T>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define all(x) begin(x), end(x)
#define fio(name) freopen(name ".in", "r", stdin); freopen(name ".out", "w", stdout);
#define psp(x) cout << x << " ";
#define pnl(x) cout << x << "\n";

vvi tcs = {
    {1, 1, 1, 2, 2, 3},
    {0,0,1,1,1,1,2,3,3}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    for (auto& tc: tcs) {
	cout << s.removeDuplicates(tc) << endl;
    }


    return 0;
}


/*
 *
 *
*/
