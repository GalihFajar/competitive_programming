#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef vector<string> vs;
typedef unordered_map<string, vs> usvs;
typedef pair<string, vector<string>> psvs;

typedef struct MTA {
    string name;
    vector<psvs> mta_routes;
} MTA;

bool is_match(vector<string>& ot_1, vector<string>& ot_2) {
    for (int i = 0; i < (int) ot_1.size(); i++) {
        if (ot_1[i] != ot_2[i]) {
            if (ot_1[i] != "*" && ot_2[i] != "*")
                return false;
        }
    }

    return true;
}

pair<string, string> solve(string& dest, vector<string>& o_r, unordered_map<string, MTA>& mta_map, unordered_map<string, bool>& visited) {
    if (mta_map.count(dest) == 0)
        return {"", ""};

    if (visited[dest])
        return {"circular", dest};
    visited[dest] = true;
    MTA next_mta = mta_map[dest];
    vector<psvs> next_mta_routes = next_mta.mta_routes;

    if (!next_mta_routes.empty()) {
        for (auto r: next_mta_routes) {
            if (is_match(r.second, o_r)) {


                if (r.first == dest)
                    return {"delivered", r.first};
                // append
                return solve(r.first, o_r, mta_map, visited);
            }
        }
    }

    return {"failed", dest};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int scn = 1;
    bool first = true;
    while (1) {
        int tc; cin >> tc; if (cin.eof()) return 0;
        unordered_map<string, MTA> mta_map;
        cout << "Scenario # " << scn++ <<'\n';

        while (tc--) {
            string mta_name; int n_routes;
            cin >> mta_name >> n_routes;
            MTA mta = {mta_name, {}};

            for (int i = 0; i < n_routes; i++) {
                string a, b, c, d, e;
                cin >> a >> b >> c >> d >> e;
                psvs route = {a, {b, c, d, e}};
                mta.mta_routes.push_back(route);
            }

            mta_map[mta_name] = mta;
        }

        cin >> tc;

        int cnt = 1;
        while (tc--) {
            string a, b, c, d, e;
            cin >> a >> b >> c >> d >> e;
            vector<string> o_r = {b, c, d, e};
            cout << cnt++ << " -- ";

            unordered_map<string, bool> visited;
            pair<string, string> result = solve(a, o_r, mta_map, visited);
            if (result.first == "delivered") {
                cout << "delivered to " << result.second << '\n';
            } else if (result.first == "circular") {
                cout << "circular routing detected by " << result.second << '\n';
            } else if (result.first == "failed") {
                cout << "unable to route at " << result.second << '\n';
            }
        }
        cout << '\n';
    }


    return 0;
}
