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

    int N; cin >> N;
    while (N--) {
        int a; int b;
        cin >> a >> b;
        int c = b ^ (b >> 1);
        cout << c << '\n';
    }

    return 0;
}
