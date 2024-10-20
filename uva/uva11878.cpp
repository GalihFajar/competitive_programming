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
    int correct = 0;

    while (1) {
        string s;
        getline(cin, s); if (cin.eof()) {
            cout << correct << '\n';
            return 0;
        };
        vector<int> nums;
        char op;
        string num_s = "";
        bool skip = false;


        for (int i = 0; i <= (int) s.size(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                num_s += s[i];
            } else {
                if (s[i] == '-' || s[i] == '+')
                    op = s[i];
                if (s[i] == '?') {
                   skip = true;
                   break;
                }
                nums.push_back(stoi(num_s));
                num_s = "";
            }
        }

        if (!skip) {
            int result = [=] ()-> int {
                if (op == '+')
                    return nums[0] + nums[1];
                return nums[0] - nums[1];
            } ();

            correct += (result == nums[2]);
        }
    }

    return 0;
}
