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

    int tc;

    cin >> tc;

    while (tc--) {
        char c; int m, n;
        int result = 0;

        cin >> c >> m >> n;
        if (cin.eof()) break;
        if (m < n)
            swap(m, n);

        if (c == 'k') {
            result = (m * n / 2) + (m * n % 2);
        } else if (c == 'r') {
            result = n;
        } else if (c == 'K') {
            result = (m / 2 + m % 2) * (n / 2 + n % 2);
        } else if (c == 'Q') {
            if (m == 1 || n == 1 || m * n <= 4)
                result = 1;
            else if (m * n <= 9) {
                result = 2;
            } else {
                result = n;
            }
        }


        cout << result << '\n';
    }

    return 0;
}


/*
m x n

knight
if m odd and n odd then: result = m * n / 2 + 1
else: result = m * n / 2

rook:
result = min(m, n)

king:
if m < n:
    swap (m, n)
result = (m / 2 + m % 2) * (n / 2 + n % 2)

queen:
if m < n:
    swap(m , n)

if m == 1 || n == 1:
    result = 1
    return;

if m * n <= 9:
    result = 2
    return;

// if m == n:
    result = n
    // return;

// result =


*/
