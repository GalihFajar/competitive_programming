#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;


unsigned long long bin_string_to_int(string& s) {
    unsigned long long out = strtoull(s.c_str(), NULL, 2);
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while (1) {
        int b, num_of_vars;

        cin >> b >> num_of_vars;
        if (cin.eof()) return 0;

        vector<pair<string, int>> vars;
        unordered_map<string, string> var_bytes_map;

        while (num_of_vars--) {
            string var;
            int num_of_bytes;
            cin >> var >> num_of_bytes;

            vars.push_back({var, num_of_bytes});
        }


        for (auto v: vars) {
            int n = v.second;
            string byte = "";

            while (n--) {
                string t;
                cin >> t;
                byte += t;
            }

            var_bytes_map[v.first] = byte;
        }

        int query;
        cin >> query;

        while (query--) {
            string temp;
            cin >> temp;

            cout << temp << "=";

            if (var_bytes_map.count(temp)) {
                unsigned long long val = bin_string_to_int(var_bytes_map[temp]);
                cout << val << '\n';
            } else {
                cout << "\n";
            }
        }
    }
    cout << "\n";


    return 0;
}
