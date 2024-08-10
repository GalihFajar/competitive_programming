#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;


typedef pair<int, int> pii;

int calculate(int x) {
    x = (x * 12) / 26;
    cout << "x: " << x << endl;
    int year = x * 2;
    int month = x * 2;
    month += 4;
    year += month / 12;

    printf("year: %d\n", year);

    return year;
}

void calculate_and_compare(int x) {
    int temp = (x * 12) / 26;
    // cout << "x: " << x << endl;
    vector<int> xs {temp, temp - 1, temp + 1, temp - 2, temp + 2};

    for (auto elem: xs) {
        // cout << "elem: " << elem << endl;
        int year = elem * 2;
        int month = elem * 2;
        month += 4;
        year += month / 12;

        // cout << "y: " << year + 2018 << endl;

        if (year + 2018 == x + 2018) {
            cout << "yes\n";
            return;
        }
    }

    cout << "no\n";
}

void advance(pii& m_y) {
    int* month = &m_y.first;
    int* year = &m_y.second;

    *year = *year + 2;
    *month = *month + 2;

    *year = *year + (*month / 13);
    *month = *month != 12 ? *month % 12 : 12;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int tc;
        cin >> tc;

        if (cin.eof())
            return 0;

        pair<int, int> base = {4, 2018};

        while (base.second < tc) {
            // printf("month: %d, year: %d\n", base.first, base.second);
            advance(base);
        }

        if (base.second == tc) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }

    }
    return 0;
}
