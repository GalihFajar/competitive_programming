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

    vector<bool> visited_pair(256, false);
    vector<vector<bool>> crossed(256, vector<bool>(256));

    string s; cin >> s;

    for (int i = 0; i < s.size(); i++) {
	if (visited_pair[s[i]]) continue;
	visited_pair[s[i]] = true;

	int begin = i;
	int end = -1;
	for (int j = i + 1; j < s.size(); j++) {
	    if (s[j] == s[begin]) {
		end = j;
		break;
	    }
	}

	vector<int> count(256);
	for (int a = begin + 1; a < end; a++) {
	    if (count[s[a]] == 0) count[s[a]]++;
	    else count[s[a]]--;
	}

	/*cout << "observing: " << s[begin] << " " << s[end] << endl;*/
	for (int k = 0; k < count.size(); k++) {
	    int elem = count[k];

	    if (elem == 1 && crossed[k][s[begin]] == 0) {
		/*printf("%c crossed %c\n", k, s[begin]);*/
		crossed[s[begin]][k] = 1;
	    }
	}
    }

    int ans = 0;

    for (int i = 0; i < 256; i++) {
	for (int j = 0; j < 256; j++) {
	    ans += crossed[i][j];
	}
    }

    cout << ans << endl;

    return 0;
}

/*
 *
 * AA
 */

