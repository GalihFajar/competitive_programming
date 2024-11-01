#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <sstream>
using namespace std;

bool is_num(char c) {
    return c >= '0' && c <= '9';
}

string get_nums(vector<string>& vs) {
    stringstream ss;

    for (int i = 0; i < vs.size(); i++) {
        for (int j = 0; j < vs[i].size(); j++) {
            if (is_num(vs[i][j]))
                ss << vs[i][j];
        }
    }

    return ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 1;

    while (1) {
        int n; cin >> n; if (n == 0) return 0;
        string temp;
        cin.ignore(100, '\n');
        vector<string> solutions;
        vector<string> answers;

        for (int i = 0; i < n; i++) {
            getline(cin, temp);
            solutions.push_back(temp);
        }

        int m; cin >> m;
        cin.ignore(100, '\n');

        for (int i = 0; i < m; i++) {
            getline(cin, temp);
            answers.push_back(temp);
        }

        cout << "Run #" << cnt++ << ": ";

        if (n == m) {
            bool accepted = true;
            for (int i = 0; i < m; i++) {
                if (solutions[i] != answers[i]) {
                    accepted = false;
                    break;
                }
            }

            if (accepted) {
                cout << "Accepted\n";
                continue;
            }
        }

        if (get_nums(solutions) == get_nums(answers))
            cout << "Presentation Error\n";
        else
            cout << "Wrong Answer\n";
    }

    return 0;
}
