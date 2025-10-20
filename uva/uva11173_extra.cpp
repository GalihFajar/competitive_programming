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


    auto inverse_gray = [](int a) -> int {
        int x = a;
        int shifter = 1;

        while (x) {
            x = a >> shifter;
            shifter = shifter << 1;
            a ^= x;

        }

        return a;
    };

    int N; cin >> N;
    while (N--) {
        int a; int b;
        cin >> a >> b;
        int c = b ^ (b >> 1);
        int k_inv = inverse_gray(c);
        cout << "k: " << b << " k-th grey: " << c << " k (inversed): " << k_inv << '\n';
        cout << c << '\n';
    }

  return 0;
}
