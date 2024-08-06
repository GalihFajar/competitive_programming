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

    int a, b;

    while(1) {
        cin >> a >> b;
        if (a <= 0 || b <= 0) return 0;
        int m = a, n = b;
        int result = 0;

        if (m < n)
            swap(m, n);

        // if (n == 2) {
        //     int newAlgo = 4 * int(m / 4) + 2 * min(2, m % 4);
        //     cout << "new algo: " << newAlgo << endl;
        // }

        if (n == 1)
            result = m;
        else if (m == 2 && n == 2)
            result = 4;
        else if (m == 3 && n == 2)
            result = 4;
        else if (n == 2)
            result = max((m * n / 2) + (m * n % 2), 4 * (m / 4) + 2 * min(2, m % 4));
        else
            result = (m * n / 2) + (m * n % 2);

        string k = result > 1 ? "knights" : "knights";

        cout << result << " "  << k << " may be placed on a " << a << " row " << b << " column board.\n";
    }

    return 0;
}
