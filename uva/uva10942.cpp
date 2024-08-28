#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<bool> vb;

vi MAX_MONTH_31 = {1, 3, 5, 7, 8, 10, 12};

template <typename T>
void printVector(vector<T> v) {
    cout << "[ ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "]\n";
}

void permutate(vl& input, vb& visited, vl& output, vector<vl>& permutations) {
    if (output.size() == input.size()) {
        permutations.push_back(output);
        return;
    }

    for (int i = 0; i < (int) input.size(); i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        output.push_back(input[i]);
        permutate(input, visited, output, permutations);
        output.pop_back();
        visited[i] = false;
    }
}

bool is_leap_year(long year) {
    if (year == 0 || year % 400 == 0)
        return true;
    else {
        if (year % 4 == 0) {
            if (year % 100 == 0)
                return false;
            return true;
        }
    }

    return false;
}

int max_month_date(int month, long year) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        } else {
            return 28;
        }
    }

    for (auto mo: MAX_MONTH_31)
        if (mo == month)
            return 31;

    return 30;
}

bool is_valid_date(int d, int m, long y) {
    // printf("d: %d, m: %d, y: %ld\n", d, m, y);
    // bool isValid = !(d <= 0 || d > max_month_date(m, y)|| m <= 0 || m > 12);
    // cout << "isValid: " << isValid << endl;

    if (d <= 0 || d > max_month_date(m, y)|| m <= 0 || m > 12)
        return false;

    return true;
}

bool is_valid_date_century(int d, int m, long y, long century) {
    // printf("d: %d, m: %d, y: %ld\n", d, m, y);
    // bool isValid = !(d <= 0 || d > max_month_date(m, y)|| m <= 0 || m > 12);
    // cout << "isValid: " << isValid << endl;

    if (d <= 0 || d > max_month_date(m, century * 100 + y)|| m <= 0 || m > 12)
        return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;

    cin >> tc;

    while (tc--) {
        // c is to determine if year is valid
        long c, x, y, z;
        cin >> c >> x >> y >> z;
        if (cin.eof()) return 0;

        vl input = {x, y, z};
        vector<vl> permutations;
        vl out;
        vb visited((int) input.size());
        vector<vl> valids;

        permutate(input, visited, out, permutations);

        for (auto p: permutations) {
            if (is_valid_date_century(p[0], p[1], p[2], c))
                valids.push_back(p);
        }

        if (valids.empty()) {
            cout << -1 << '\n'; continue;
        }

        // for (auto v: valids) {
        //     printVector(v);
        // }

        sort(valids.begin(), valids.end(), [](vl& a, vl& b) -> bool {
            return a[2] < b[2] || (a[2] == b[2] && a[1] < b[1]) || (a[2] == b[2] && a[1] == b[1] && a[0] < b[0]);
        });


        // cout << "after sorted: " << endl;
        // for (auto v: valids) {
        //     printVector(v);
        // }

        vl selected = valids[0];

        cout << setw(2) << setfill('0');
        cout << selected[2]; cout << " ";
        cout << setw(2) << setfill('0');
        cout << selected[1]; cout << " ";
        cout << setw(2) << setfill('0');
        cout << selected[0]; cout << "\n";
    }

    return 0;
}
