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

    int input;
    while (cin >> input, input != 0) {
        vector<pair<int, int>> pages;


        // case pages >= 2
        if (input >= 2) {
            int temp_input = input;
            if (input > 3 && input % 2 != 0) {
                // cout << "mashook\n";
                temp_input = (input / 4 + (input % 4 != 0)) * 4;
                // cout << "temp input: " << temp_input << endl;
            }

            int left = 1;
            int right = temp_input;

            int blanks = temp_input >= 4 ? temp_input % 4 : 4 - temp_input;
            while (blanks--) {
                pages.push_back({left++, 0});
            }

            while (left < right) {
                pages.push_back({left++, right--});
            }

            if (input > 3 && input % 2 != 0) {
                for (pair<int, int>& p: pages) {
                    if (p.first > input)
                        p.first = 0;
                    if (p.second > input)
                        p.second = 0;
                }
            }
        } else {
            pages.push_back({1, 0});
        }

        int count = 0;
        cout << "Printing order for " << input << " pages:\n";
        for (int i = 0; i < (int) pages.size(); i++) {
            if (i % 2 == 0) {
                cout << "Sheet " << count / 2 + 1 << ", front: " << (pages[i].second != 0 ? to_string(pages[i].second) : "Blank") << ", " << (pages[i].first != 0 ? to_string(pages[i].first) : "Blank") << '\n';
            } else {
                cout << "Sheet " << count / 2 + 1 << ", back : " << (pages[i].first != 0 ? to_string(pages[i].first) : "Blank") << ", " << (pages[i].second != 0 ? to_string(pages[i].second) : "Blank") << '\n';
            }
            count++;
        }
    }

    return 0;
}
