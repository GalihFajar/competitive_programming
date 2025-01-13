#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<unsigned int> v;
    unsigned int in;

    while (cin >> in) {
        v.push_back(in);
        size_t len = v.size();
        if ((len & 1) == 1) {
            int mid = (1 + len) / 2;
            nth_element(v.begin(), v.begin() + (mid - 1), v.end());
            cout << v[mid - 1] << '\n';
        } else {
            int mid_a = len / 2;
            int mid_b = mid_a + 1;
            int out = 0;
            nth_element(v.begin(), v.begin() + (mid_a - 1), v.end());
            out += v[mid_a - 1];
            nth_element(v.begin(), v.begin() + (mid_b - 1), v.end());
            out += v[mid_b - 1];
            cout << out / 2 << '\n';
        }
    }

    return 0;
}
