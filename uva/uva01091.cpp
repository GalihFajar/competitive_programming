#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, char> encodings {
    {"00001", '0'},
    {"10001", '1'},
    {"01001", '2'},
    {"11000", '3'},
    {"00101", '4'},
    {"10100", '5'},
    {"01100", '6'},
    {"00011", '7'},
    {"10010", '8'},
    {"10000", '9'},
    {"00100", '-'},
    {"00110", 's'}
};

// cool but unused clustering algorithm
pair<unordered_map<int, int>, pair<double, double>> clusters(vector<int>& v) {

    unordered_map<int, int> key_cluster;
    int i = 0;
    int j = v.size() - 1;
    int iter = i;
    vector<int> temp;
    double current_mean = 0;
    int current_cluster = 0;
    vector<double> means;

    while (iter <= j) {
        if (temp.empty()) {
            temp.push_back(v[iter]);
            current_mean = v[iter++];
        } else {
            double new_mean = (current_mean * ((int) temp.size()) + v[iter]) / ((int) temp.size() + 1);
            double low_range = (new_mean) * 0.95;
            double high_range = (new_mean) * 1.05;

            double v_iter_high = v[iter] * 1.05;
            double v_iter_low = v[iter] * .95;

            if (
                (v[iter] >= low_range && v[iter] <= high_range ) ||
                (v_iter_low >= low_range && v_iter_low <= high_range ) ||
                (v_iter_high >= low_range && v_iter_high <= high_range)
            ) {
                current_mean = new_mean;
                temp.push_back(v[iter]);
                iter++;
            } else {
                for (auto elem: temp) {
                    key_cluster[elem] = current_cluster;
                }

                means.push_back(current_mean);

                current_cluster++;

                temp.clear();
                temp.push_back(v[iter]);
                current_mean = v[iter++];
            }
        }
    }

    if (!temp.empty()) {
        for (auto elem: temp) {
            key_cluster[elem] = current_cluster;
        }

        means.push_back(current_mean);
    }

    return {key_cluster, {means[0], means.back()}};
}

char check_region(vector<int>& inputs, int i, int j, double mid) {

    vector<int> v(5, -1);

    string string_v = "";

    for (int a = i, iter = 0; a <= j; a++, iter++) {
        // cout << "inputs[a]: " << inputs[a] << endl;
        char c = inputs[a] < mid ? '0' : '1';
        string_v += c;
    }
    // cout << "string_v: " << string_v << endl;

    if (!encodings.count(string_v)) {
        return '!';
    }


    return encodings[string_v];
}

char calculate_C(string& s) {
    // cout << "s: " << s << endl;
    int n = (int) s.size();
    int C = 0;

    for (int i = 0; i < (int) n; i++) {
        C += ((n - (i + 1)) % 10 + 1) * (s[i] == '-' ? 10 : s[i] - '0');
    }

    int C_int = C % 11;
    char c = C_int == 10 ? '-' : C_int + '0';

    return c;
}

// s = message to be encoded + c
char calculate_K(string& s) {
    int n = (int) s.size();
    int K = 0;

    for (int i = 0; i < (int) n; i++) {
        K += (((n - 1) - (i + 1) + 1) % 9 + 1) * (s[i] == '-' ? 10 : s[i] - '0');
    }

    int K_int = K % 11;
    char k = K_int == 10 ? '-' : K_int + '0';

    return k;
}

void print_validity(string& out) {
    if (out[0] != 's' || out.back() != 's') {
        cout << "bad code\n";
        return;
    }

    for (auto c: out) {
        if (c == '!') {
            cout << "bad code\n";
            return;
        }
    }

    string temp = "";
    for (int i = 1; i < (int) out.size() - 3; i++) {
        temp += out[i];
    }

    char C = out[(int) out.size() - 3];
    char K = out[(int) out.size() - 2];

    if (C != (calculate_C(temp))) {
        cout << "bad C\n";
        return;
    }

    char c = C;
    temp += c;

    if (K != (calculate_K(temp)))  {
        cout << "bad K\n";
        return;
    }

    temp.pop_back();

    cout << temp << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int c = 0;

    while (1) {
        int n;
        cin >> n;
        if (n == 0) return 0;
        vector<int> inputs;

        cout << "Case " << ++c << ": ";

        while (n--) {
            int input;
            cin >> input;

            inputs.push_back(input);
        }

        string out = "";
        int max_w = 0, min_w = 500;

        for (int i = 0; i < (int) inputs.size(); i++) {
            max_w = max(max_w, inputs[i]); min_w = min(min_w, inputs[i]);
        }

        double t = (max_w + min_w) / 2.0;
        max_w = 0, min_w = 500;

        for (int i = 0; i < (int) inputs.size(); i++) {
            int temp = 0;

            if (inputs[i] < t)
                temp = inputs[i] * 2;
            else
                temp = inputs[i];

            min_w = min(min_w, temp); max_w = max(max_w, temp);
        }

        if (max_w * 95 > min_w * 105) {
            cout << "bad code\n";
            continue;
        }

        bool is_bad = false;
        // check normal
        for (int i = 0; i < (int) inputs.size(); i += 6) {
            out += check_region(inputs, i, i + 4, t);

            if (i + 5 < (int) inputs.size() && inputs[i + 5] > t) {
                cout << "bad code\n";
                is_bad = true;
                break;
            }

            if (is_bad)
                break;
        }

        if (is_bad)
            continue;

        reverse(inputs.begin(), inputs.end());
        string out_reverse = "";

        for (int i = 0; i < (int) inputs.size(); i += 6) {
            out_reverse += check_region(inputs, i, i + 4, t);
        }

        if (!(out[0] == 's' && out.back() == 's')) {
            out = out_reverse;
        }

        print_validity(out);
    }

    return 0;
}
