#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef struct pan {
    int weight_at;
    int weight;
    string weights;
} pan;


bool is_weight(char c) {
    return c >= 'A' && c <= 'Z';
}

int calc_weight(char c) {
    if (!is_weight(c)) return 0;

    int zeroes_left = __builtin_clz(c);
    int zeroes_right = __builtin_ctz(c);
    int ones = __builtin_popcount(c);
    int zeroes = 32 - (zeroes_left + zeroes_right + ones);

    return (int) ((500 * ones) + (250 * zeroes) + (250 * zeroes_right));
}

// lor_input: left or right input
pan vs_to_pan(vector<string>& lor_input) {
    if (lor_input.empty() || lor_input[0].empty() || lor_input[0].size() > 8) {
        return {-1, 0, "invalid"};
    }

    pan ret_pan = {-1, 0, ""};

    int weight_at = [&]() -> int {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < lor_input[i].size(); j++) {
                if (lor_input[i][j] == '_') {
                    return i - 1;
                }
            }
        }

        return -1;
    }();

    if (weight_at != -1) {
        ret_pan.weight_at = weight_at;

        for (int i = 0; i < lor_input[weight_at].size(); i++) {
            char temp = lor_input[weight_at][i];

            if (is_weight(temp)) {
                ret_pan.weights += temp;
            }

            ret_pan.weight += calc_weight(temp);
        }
    }
    return ret_pan;
}

vector<string> pan_to_vs(pan& p) {
    string weight_str = [&]() -> string {
        string ret;
        ret += '/';
        ret += p.weights;
        int str_len = (int) p.weights.size();
        string dots(6 - str_len, '.');
        ret += dots;
        ret += '\\';

        return ret;
    }();
    vector<string> out;

    if (p.weight_at == 3) {
        out = {
            ".../\\...",
            "../..\\..",
            "./....\\.",
            weight_str,
            "\\______/",
            "........",
            "........"
        };

    } else if (p.weight_at == 5) {
        out = {
            "........",
            "........",
            ".../\\...",
            "../..\\..",
            "./....\\.",
            weight_str,
            "\\______/"
        };
    } else if (p.weight_at == 4) {
        out = {
            "........",
            ".../\\...",
            "../..\\..",
            "./....\\.",
            weight_str,
            "\\______/",
            "........"
        };
    }

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    cin.ignore(100, '\n');
    int cnt = 1;
    while (tc--) {
        vector<string> input;

        for (int i = 0; i <= 7; i++) {
            string s;
            getline(cin, s);
            if (i < 7)
                input.push_back(s);
        }

        cout << "Case " << cnt++ << ":\n";

        vector<string> input_left, input_right;
        for (int i = 0; i < 7; i++) {
            input_left.push_back(input[i].substr(0, 8));
            input_right.push_back(input[i].substr(10, 8));
        }

        pan l_pan = vs_to_pan(input_left), r_pan = vs_to_pan(input_right);

        auto print_scales = [](vector<string>& l_vs_, vector<string>& r_vs_ ) {
            for (int i = 0; i < (int) l_vs_.size(); i++) {
                cout << l_vs_[i]  << "||" << r_vs_[i] << '\n';
            }
        };

        if (l_pan.weight == r_pan.weight) {
            if (l_pan.weight_at == 4 && r_pan.weight_at == 4)
                cout << "The figure is correct.\n";
            else  {
                l_pan.weight_at = 4; r_pan.weight_at = 4;
                vector<string> l_vs = pan_to_vs(l_pan), r_vs = pan_to_vs(r_pan);
                print_scales(l_vs, r_vs);
            }
        } else if (l_pan.weight > r_pan.weight) {
            if (l_pan.weight_at == 5 && r_pan.weight_at == 3)
                cout << "The figure is correct.\n";
            else  {
                l_pan.weight_at = 5; r_pan.weight_at = 3;
                vector<string> l_vs = pan_to_vs(l_pan), r_vs = pan_to_vs(r_pan);
                print_scales(l_vs, r_vs);
            }
        } else {
            if (l_pan.weight_at == 3 && r_pan.weight_at == 5)
                cout << "The figure is correct.\n";
            else  {
                l_pan.weight_at = 3; r_pan.weight_at = 5;
                vector<string> l_vs = pan_to_vs(l_pan), r_vs = pan_to_vs(r_pan);
                print_scales(l_vs, r_vs);
            }
        }
    }


    return 0;
}
