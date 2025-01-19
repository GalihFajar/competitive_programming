#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef struct Date {
    int d;
    int m;
    int y;
} Date;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<string, Date>> v;
    pair<string, Date> in;
    string s; int a, b, c;
    int n;

    cin >> n;
    while (n--) {
        cin >> s >> a >> b >> c;
        v.push_back({s, {a, b, c}});
    }

    sort(v.begin(), v.end(), [](pair<string, Date>& p1, pair<string, Date>& p2) -> bool {
        if (p1.second.y != p2.second.y) 
            return p1.second.y > p2.second.y;
        if (p1.second.m != p2.second.m) 
            return p1.second.m > p2.second.m;
        return p1.second.d > p2.second.d;
    });

    cout << v[0].first << endl;

    sort(v.begin(), v.end(), [](pair<string, Date>& p1, pair<string, Date>& p2) -> bool {
        if (p1.second.y != p2.second.y) 
            return p1.second.y < p2.second.y;
        if (p1.second.m != p2.second.m) 
            return p1.second.m < p2.second.m;
        return p1.second.d < p2.second.d;
    });

    cout << v[0].first << endl;


    return 0;
}
