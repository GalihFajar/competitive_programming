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


    int n, m;
    cin >> n >> m;
    int nt = n;
    vector<string> spotty, plain;

    while (nt--) {
	    string s;
	    cin >> s;
	    spotty.push_back(s);
    }

    nt = n;

    while (nt--) {
	    string s;
	    cin >> s;
	    plain.push_back(s);
    }
    int ans = 0;
    string actg = "ACTG";

    for (int i = 0; i < m; i++) {
	    vector<int> cnt_spotty(256, 0), cnt_plain(256, 0);
	    for (int j = 0; j < spotty.size(); j++) {
		    cnt_spotty[spotty[j][i]]++;
	    }

	    for (int j = 0; j < plain.size(); j++) {
		    cnt_plain[plain[j][i]]++;
	    }

	    bool check = true;
	    for (int k = 0; k < actg.size(); k++) {
		    if (cnt_plain[actg[k]] != 0 && cnt_spotty[actg[k]] != 0) check = false;
	    }

	    ans += (int) check;
    }

    cout << ans << endl;

    return 0;
}

