#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<char> chr_list;

void fill_char() {
    for (char c = 'A'; c <= 'Z'; c++)
        chr_list.push_back(c);

    for (char c = 'a'; c <= 'z'; c++)
        chr_list.push_back(c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fill_char();

    int tc;

    while(cin >> tc) {
        int h = 2, w = tc, l = tc;

        cout << h << " " << w << " " << l << '\n';
        for (int k = 0; k < tc; k++) {
            for (int i = 0; i < tc; i++) {
                cout << chr_list[i];
            }
            cout << '\n';
        }
        cout << '\n';

        for (int i = 0; i < tc; i++) {
            for (int j = 0; j < tc; j++) {
                cout << chr_list[i];
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}
