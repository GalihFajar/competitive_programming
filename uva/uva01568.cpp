#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

void init_p_table(unordered_map<char, float>& p_table) {
    p_table['C'] = 12.01;
    p_table['H'] = 1.008;
    p_table['O'] = 16.00;
    p_table['N'] = 14.01;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<char, float> p_table;
    init_p_table(p_table);

    int tc;
    cin >> tc;
    while (tc--) {
        string input;
        cin >> input;
        float mol_mass = 0;

        for (int i = (int) input.size() - 1; i >= 0; i--) {
            int multi = 0;
            int multi_mult = 1;

            while (!p_table.count(input[i])) {
                multi += (input[i] - '0') * multi_mult;
                multi_mult *= 10;
                i--;
            }

            multi = multi != 0 ? multi : 1;

            mol_mass += p_table[input[i]] * multi;
        }

        cout << fixed;
        cout << setprecision(3) << mol_mass << '\n';
    }

    return 0;
}
