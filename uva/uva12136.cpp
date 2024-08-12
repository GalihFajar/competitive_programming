#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> parse_in(string& s) {
    vector<string> hour_min;
    string temp = "";
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == ':') {
            hour_min.push_back(temp);
            temp = "";
            continue;
        }

        temp += s[i];
    }

    hour_min.push_back(temp);

    return hour_min;
}

int to_min(vector<string>& hour_min) {
    return stoi(hour_min[0]) * 60 + stoi(hour_min[1]);
}

int to_min_complete(string& s) {
    vector<string> a = parse_in(s);
    return to_min(a);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    int cnt = 1;

    while (tc--) {
        string a_s, b_s, c_s, d_s;
        cin >> a_s >> b_s >> c_s >> d_s;
        cout << "Case " << cnt++ << ": ";

        int a = to_min_complete(a_s), b = to_min_complete(b_s);
        int c = to_min_complete(c_s), d = to_min_complete(d_s);

        if ((d < a || c > b)) {
            cout << "Hits Meeting\n";
        } else {
            cout << "Mrs Meeting\n";
        }
    }

    return 0;
}

/*

case d < a
     a b
c d

case b < c
     a b
           c d

*/
