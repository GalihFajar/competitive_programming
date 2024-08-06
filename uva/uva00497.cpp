#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

void insert_stack_monotonic(vector<int>& s, vector<vector<int>>& s_total, int elem) {
    if (s.empty()) {
        s.push_back(elem);
        s_total.push_back(s);
        return;
    }

    if (s.back() > elem)
        s_total.push_back(s);
    while (!s.empty() && s.back() > elem) {
        s.pop_back();
    }

    s.push_back(elem);
    s_total.push_back(s);
}

vector<int> LIS(vector<int>& v) {
    vector<int> length(v.size(), 1);
    vector<int> prev(v.size());
    vector<int> out;
    int temp = -1;
    int temp_idx = 1;

    for (int i = 0; i < (int) length.size(); i++) {
        prev[i] = i;
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                if (length[i] < length[j] + 1) {
                    length[i] = max(length[i], length[j] + 1);
                    prev[i] = j;
                }
            }
        }

        if (temp < length[i]) {
            temp = max(temp, length[i]);
            temp_idx = i;
        }
    }

    // cout << "end: " << v[temp_idx] << endl;
    out.push_back(v[temp_idx]);
    int idx = prev[temp_idx];
    if (idx != prev[idx]) {
        while (idx != prev[idx]) {
            out.push_back(v[idx]);
            idx = prev[idx];
        }
        out.push_back(v[idx]);
    }

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string tc_string;
    getline(cin, tc_string);

    int tc = stoi(tc_string);
    bool first = true;

    while (tc--) {
        vector<int> s; vector<int> v;
        vector<vector<int>> s_total;

        string input;
        if (!first) cout << '\n';
        if (first) {
            getline(cin, input);
            first = false;
        }

        while (getline(cin, input), input.length() != 0) {
            v.push_back(stoi(input));
        }

        auto out = LIS(v);

        // perform LIS

        // int max_size = -1;
        // int biggest_s = 0;

        // for (int i = 0; i < (int) s_total.size(); i++) {
        //     if (max_size < (int) s_total[i].size()) {
        //         max_size = (int) s_total[i].size();
        //         biggest_s = i;
        //     }
        // }

        cout << "Max hits: " << out.size() << '\n';
        while(!out.empty()) {
            cout << out.back() << '\n';
            out.pop_back();
        }
        // for (auto i: out) {
        //     cout << i << '\n';
        // }

        // for (int i = 0 ; i < (int) s_total[biggest_s].size(); i++)
        //     cout << s_total[biggest_s][i] << '\n';
    }

    return 0;
}

/*
1
6
2
3
5


99
1
98
2
3
4
5

1 2 3 4 5


1 2 3 4 5
*/
