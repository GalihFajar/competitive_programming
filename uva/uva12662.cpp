#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef vector<pair<pair<string, char>, int>> vppsci;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; 
    vector<string> in;
    for (int i = 0; i < tc; i++) {
        string s; cin >> s;
        in.push_back(s);
    }

    vppsci v(tc, {{}, 9999});
    for (int i = 0; i < tc; i++) {
        if (in[i] != "?") {
            string temp = "";
            temp += in[i];
            v[i] = {{temp, '_'}, 0};
            continue;
        }

        for (int j = 0; j < tc; j++) {
            if (in[j] == "?") continue;
            int dist = abs(i - j);
            char pos = (i - j) < 0 ? 'L' : 'R';
            if (v[i].second == 9999) { 
                string temp = "";
                temp += in[j];
                v[i].first = {temp, pos};
                v[i].second = dist;
            } else {
                if (dist == v[i].second) {
                    if (pos == 'R') {
                        string temp = "";
                        temp += in[j];
                        temp += "|";
                        temp += v[i].first.first;
                        v[i] = {{temp, 'M'}, dist};
                    } else {
                        string temp = "";
                        temp += v[i].first.first;
                        temp += "|";
                        temp += in[j];
                        v[i] = {{temp, 'M'}, dist};
                    }
                } else if (dist < v[i].second) {
                    string temp = "";
                    temp += in[j];
                    v[i] = {{temp, pos}, dist};
                }
            }
        }
    }

    auto solver = [&](int in) {
        int idx = in - 1;
        if (v[idx].second == 0) {
            cout << v[idx].first.first << '\n';
        } else if (v[idx].first.second == 'M') {
            cout << "middle of "; 
            int iter = 0;
            string str = v[idx].first.first;
            while (str[iter] != '|') {
                cout << str[iter];
                iter++;
            }
            iter++;
            cout << " and "; 
            while (iter < str.size()) {
                cout << str[iter];
                iter++;
            }
            cout << '\n';
        } else {
            string temp;
            if (v[idx].first.second == 'R') {
                temp = "right of";
            } else {
                temp = "left of";
            }

            for (int i = 0; i < v[idx].second; i++) {
                cout << temp << " ";
            }
            cout << v[idx].first.first << '\n';
        }
    };

    cin >> tc;
    while (tc--) {
        int t; cin >> t;
        solver(t);
    }

    return 0;
}
