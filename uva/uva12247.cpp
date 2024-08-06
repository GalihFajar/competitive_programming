#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    while(1) {
        vector<bool> visited(55, false);
        vector<int> p1, p2;
        int a, b, c, d, e;

        cin >> a >> b >> c >> d >> e;
        if (a == 0 && b == 0 && c == 0 && d == 0)
            return 0;

        p1.push_back(a); p1.push_back(b); p1.push_back(c);
        p2.push_back(d); p2.push_back(e);

        sort(p1.begin(), p1.end()); sort(p2.begin(), p2.end());
        visited[a] = true;
        visited[b] = true;
        visited[c] = true;
        visited[d] = true;
        visited[e] = true;

        int card = 53;

        /*
        Case 1:
        a b c d e
        */

        if (p2[0] > p1[2]) {
            for (int i = 1; i <= 52 && i < card; i++) {
                if (!visited[i])
                    card = i;
            }
        }

        /*
        Case 2:
        d a b c e (worst case)
        */
        if (p2[1] > p1[2]) {
            for (int i = p1[2] + 1; i <= 52 && i < card; i++) {
                if (!visited[i])
                    card = i;
            }
        }

        /*
        Case 3:
        a b d e c (worst case)
        */
        if (p2[0] > p1[1]) {
            for (int i = p1[1] + 1; i <= 52 && i < card; i++) {
                if (!visited[i])
                    card = i;
            }
        }


        // other than cases above, there are unwinable games

        if (card > 52)
            card = -1;

        cout << card << '\n';
    }

    return 0;
}
