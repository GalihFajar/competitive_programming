#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef string fs(int);
typedef fs* pfs;

string h_type_1(int n) {
    string out = " ";

    for (int i = 0; i < n; i++) {
        out += "-";
    }

    out += ' ';

    return out;
}

string h_type_2(int n) {
    string out;

    for (int i = 0; i < n + 2; i++) {
        out += " ";
    }

    return out;
}

string v_type_1(int n) {
    string out = "";
    int n_of_space = n + 1;

    for (int i = 0; i < n_of_space; i++) {
        out += " ";
    }

    out += '|';

    return out;
}

string v_type_2(int n) {
    string out = "";
    int n_of_space = n + 1;

    out += '|';
    for (int i = 0; i < n_of_space; i++) {
        out += " ";
    }

    return out;
}

string v_type_3(int n) {
    string out = "|";

    for (int i = 0; i < n; i++) {
        out += " ";
    }

    out += '|';

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<fs*>> nums {
        {&h_type_1, &v_type_3, &h_type_2, &v_type_3, &h_type_1}, // 0
        {&h_type_2, &v_type_1, &h_type_2, &v_type_1, &h_type_2}, // 1
        {&h_type_1, &v_type_1, &h_type_1, &v_type_2, &h_type_1}, // 2
        {&h_type_1, &v_type_1, &h_type_1, &v_type_1, &h_type_1}, // 3
        {&h_type_2, &v_type_3, &h_type_1, &v_type_1, &h_type_2}, // 4
        {&h_type_1, &v_type_2, &h_type_1, &v_type_1, &h_type_1}, // 5
        {&h_type_1, &v_type_2, &h_type_1, &v_type_3, &h_type_1}, // 6
        {&h_type_1, &v_type_1, &h_type_2, &v_type_1, &h_type_2}, // 7
        {&h_type_1, &v_type_3, &h_type_1, &v_type_3, &h_type_1}, // 8
        {&h_type_1, &v_type_3, &h_type_1, &v_type_1, &h_type_1}, // 9
    };

    // cout << h_type_1(2) << endl;
    // cout << v_type_1(2) << endl;
    // cout << v_type_2(2) << endl;
    // cout << v_type_3(2) << endl;
    bool first = true;


    while (1) {
        int s;
        string n;
        cin >> s >> n;
        if (s == 0) return 0;

        int iter = 0;
        int cnt = 0;
        // if (!first) {
        //     cout << '\n';
        // } else {
        //     first = false;
        // }

        while (iter < 5) {
            int temp = iter == 1 || iter == 3 ? s : 1;

            while (temp--) {
                string row_out = "";
                for (int i = 0; i < (int) n.size(); i++) {
                    int t = n[i] - '0';
                    row_out += nums[t][iter](s);
                    if (i != (int) n.size() - 1)
                        row_out += ' ';
                }

                cout << row_out << '\n';
            }
            iter++;
        }
        cout << '\n';
    }

    return 0;
}
