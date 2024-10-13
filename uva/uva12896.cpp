#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<char, string> num_chr_map = {
    {1, ".,?\""},
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"},
    {0, " "}
};

char map_num(char num, char mov) {
    return num_chr_map[num][mov - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {
        int len; cin >> len;
        int temp = len;

        vector<char> input;
        while (len--) {
            int tmp;
            cin >> tmp;
            input.push_back(tmp);
        }

        len = temp;
        int iter = 0;
        while (len--) {
            int tmp;
            cin >> tmp;
            cout << map_num(input[iter++], tmp);
        }

        cout << '\n';
    }


    return 0;
}
